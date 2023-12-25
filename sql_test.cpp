#include <iostream>
#include <sqlite3.h> 
using namespace std;
static int callback(void *data, int argc, char **argv, char **azColName){
   int* agePtr = static_cast<int*>(data);

   for(int i = 0; i < argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
      if (string(azColName[i]) == "AGE" && argv[i]) {
         *agePtr = atoi(argv[i]);
      }
   }
   
   printf("\n");
   return 0;
}

int main(int argc, char* argv[]) {
   sqlite3 *db;
   int rc;
   /*
   string sql = "CREATE TABLE PERSON("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "NAME           TEXT    NOT NULL, "
                      "SURNAME          TEXT     NOT NULL, "
                      "AGE            INT     NOT NULL, "
                      "ADDRESS        CHAR(50), "
                      "SALARY         REAL );";
   */
   //string sql = "INSERT INTO PERSON (ID, NAME, SURNAME, AGE, ADDRESS, SALARY) VALUES (2, 'John', 'Doe', 30, '123 Main St', 50000.00 ); ";
   string sql = "SELECT * FROM PERSON WHERE ID=2;";

   rc = sqlite3_open("mydata.db", &db);

   if(rc) {  
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return 0;
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }

   char *errorMessage = 0;
   int age=0;
   rc = sqlite3_exec(db, sql.c_str(), callback, &age, &errorMessage); 
   cout<<age<<endl;
   if (rc != SQLITE_OK) {
      cerr << "SQL error: " << errorMessage << endl;
      sqlite3_free(errorMessage);
   } else {
      cout << "Operation done successfully" << endl; 
   }
    
   sqlite3_close(db);
   return 0;
}
