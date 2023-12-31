#include <iostream>
#include "sqlitee3.h"
#include <string>

using namespace std;
int Sql::callback(void *data, int argc, char **argv, char **azColName){
   //int* agePtr = static_cast<int*>(data);
   for(int i = 0; i < argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}
// callback1 is for getting the last id.
int Sql::callback1(void *data, int argc, char **argv, char **azColName){
    int* maxIdPtr = static_cast<int*>(data);
    if (argc > 0 && argv[0]) {
        *maxIdPtr = atoi(argv[0]);
    }
    return 0;
}
int Sql::id_counter = 0;

Sql::Sql(string filename){
   rc = sqlite3_open(filename.c_str(), &db);
   string sql = "SELECT MAX(ID) FROM PERSON;";
   char *errorMessage = 0;
   rc = sqlite3_exec(db, sql.c_str(), callback1, &id_counter, &errorMessage); 
   cout<<"ID_COUNTER = "<<id_counter<<endl; // print initialized last id;
   if (rc != SQLITE_OK) {
      cerr << "SQL error: " << errorMessage << endl;
      sqlite3_free(errorMessage);
   }

   if(rc) {  
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
   }
}
Sql::~Sql(){
   sqlite3_close(db);
}
void Sql::print_worker_by_id(int ID){
   //string sql = "INSERT INTO PERSON (ID, NAME, SURNAME, AGE, ADDRESS, SALARY) VALUES (2, 'John', 'Doe', 30, '123 Main St', 50000.00 ); ";
   string sql = "SELECT * FROM PERSON WHERE ID="+to_string(ID)+";";
   char *errorMessage = 0;
   rc = sqlite3_exec(db, sql.c_str(), callback, 0, &errorMessage); 
   //cout<<salary<<endl;
   if (rc != SQLITE_OK) {
      cerr << "SQL error: " << errorMessage << endl;
      sqlite3_free(errorMessage);
   }
}
void Sql::print_worker_by_fullname(string fullname){
   //string sql = "INSERT INTO PERSON (ID, NAME, SURNAME, AGE, ADDRESS, SALARY) VALUES (2, 'John', 'Doe', 30, '123 Main St', 50000.00 ); ";
   string name=fullname.substr(0, fullname.find(" "));
   string surname=fullname.substr(fullname.find(" ")+1, fullname.length());
   //cout<<name+" "+surname<<endl;
   string sql = "SELECT * FROM PERSON WHERE NAME = '"+name+"' AND SURNAME = '"+surname+"';";
   char *errorMessage = 0;
   rc = sqlite3_exec(db, sql.c_str(), callback, 0, &errorMessage); 
   //cout<<salary<<endl;
   if (rc != SQLITE_OK) {
      cerr << "SQL error: " << errorMessage << endl;
      sqlite3_free(errorMessage);
   }
}
void Sql::add_worker(string NAME, string SURNAME, string JOB, int AGE, string ADDRESS, double SALARY){
   id_counter+=1;
   string sql = "INSERT INTO PERSON (ID, NAME, SURNAME, JOB, AGE, ADDRESS, SALARY) VALUES ("+to_string(id_counter)+", '"+NAME+"', '"+SURNAME+"', '"+JOB+"', "+to_string(AGE)+", '"+ADDRESS+"', "+to_string(SALARY)+"); ";
   //string sql = "SELECT * FROM PERSON WHERE ID="+to_string(ID)+";";
   char *errorMessage = 0;
   rc = sqlite3_exec(db, sql.c_str(), callback, 0, &errorMessage); 
   //cout<<salary<<endl;
   if (rc != SQLITE_OK) {
      cerr << "SQL error: " << errorMessage << endl;
      sqlite3_free(errorMessage);
   }
}
void Sql::print_all_workers(){
   string sql = "SELECT * FROM PERSON;";
   char *errorMessage = 0;
   rc = sqlite3_exec(db, sql.c_str(), callback, 0, &errorMessage); 
   //cout<<salary<<endl;
   if (rc != SQLITE_OK) {
      cerr << "SQL error: " << errorMessage << endl;
      sqlite3_free(errorMessage);
   }
}
void Sql::delete_worker(int ID) {
   // Construct the SQL DELETE statement
   string sql = "DELETE FROM PERSON WHERE ID = " + to_string(ID) + ";";
   id_counter-=1;
   char *errorMessage = nullptr;
   rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errorMessage);

   if (rc != SQLITE_OK) {
      cerr << "SQL error: " << errorMessage << endl;
      sqlite3_free(errorMessage);
   }
}

void Sql::update_worker(int ID, string column_name, string data){
   string sql = "UPDATE PERSON SET "+column_name+"='"+data+"' WHERE ID="+to_string(ID)+";";
   char *errorMessage = 0;
   rc = sqlite3_exec(db, sql.c_str(), callback, 0, &errorMessage); 
   //cout<<salary<<endl;
   if (rc != SQLITE_OK) {
      cerr << "SQL error: " << errorMessage << endl;
      sqlite3_free(errorMessage);
   }
}
void Sql::update_worker(int ID, string column_name, int data){
   string sql = "UPDATE PERSON SET "+column_name+"="+to_string(data)+" WHERE ID="+to_string(ID)+";";
   char *errorMessage = 0;
   rc = sqlite3_exec(db, sql.c_str(), callback, 0, &errorMessage); 
   //cout<<salary<<endl;
   if (rc != SQLITE_OK) {
      cerr << "SQL error: " << errorMessage << endl;
      sqlite3_free(errorMessage);
   }
}
double Sql::get_total_salaries() {
    double totalSalaries = 0.0;
    char* errMsg = nullptr;
    string sql = "SELECT SUM(SALARY) FROM PERSON;";  // Assuming your table is named 'workers'

    auto callback = [](void* data, int argc, char** argv, char** azColName) -> int {
        double* totalSalaries = static_cast<double*>(data);
        if (argc > 0 && argv[0]) {
            *totalSalaries = atof(argv[0]);
        }
        return 0;
    };

    if (sqlite3_exec(db, sql.c_str(), callback, &totalSalaries, &errMsg) != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }

    return totalSalaries;
}