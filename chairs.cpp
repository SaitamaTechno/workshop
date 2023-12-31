#include "chairs.h"
#include <iostream>
int Chairs::next_id = 1;

Chairs::Chairs(string filename) {
    int rc = sqlite3_open(filename.c_str(), &db);
    if (rc != SQLITE_OK) {
        cerr << "Cannot open database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        exit(1);
    }
}

Chairs::~Chairs() {
    sqlite3_close(db);
}

void Chairs::add_chair(double price) {
    char* errMsg = nullptr;
    string sql = "INSERT INTO CHAIRS (ID, PRICE) VALUES (" +
                 to_string(next_id++) + ", " + to_string(price) + ");";

    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL Error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}

void Chairs::update_chair_price(int id, double newPrice) {
    char* errMsg = nullptr;
    string sql = "UPDATE CHAIRS SET PRICE = " + to_string(newPrice) + 
                 " WHERE ID = " + to_string(id) + ";";

    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL Error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}

void Chairs::delete_chair(int id) {
    char* errMsg = nullptr;
    string sql = "DELETE FROM CHAIRS WHERE ID = " + to_string(id) + ";";

    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL Error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}

void Chairs::print_chair_info(int id) {
    char* errMsg = nullptr;
    string sql = "SELECT * FROM CHAIRS WHERE ID = " + to_string(id) + ";";
    int rc = sqlite3_exec(db, sql.c_str(), callback, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL Error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}

int Chairs::callback(void *NotUsed, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << "\n";
    }
    cout << "\n";
    return 0;
}
int Chairs::get_first_empty_chair_id() {
    string sql = "SELECT ID FROM CHAIRS WHERE PRICE = 0 LIMIT 1;";
    int chairId = -1; // Default value if no empty chair is found
    char* errMsg = nullptr;

    if (sqlite3_exec(db, sql.c_str(), single_id_callback, &chairId, &errMsg) != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
    return chairId;
}

double Chairs::get_chair_price(int id) {
    string sql = "SELECT PRICE FROM CHAIRS WHERE ID = " + to_string(id) + ";";
    double price = 0.0;
    char* errMsg = nullptr;

    if (sqlite3_exec(db, sql.c_str(), single_double_callback, &price, &errMsg) != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
    return price;
}
int Chairs::single_id_callback(void* data, int argc, char** argv, char** azColName) {
    int* chairId = static_cast<int*>(data);
    if (argc > 0 && argv[0]) {
        *chairId = stoi(argv[0]);
    }
    return 0;
}


int Chairs::single_double_callback(void* data, int argc, char** argv, char** azColName) {
    double* price = static_cast<double*>(data);
    if (argc > 0 && argv[0]) {
        *price = stod(argv[0]);
    }
    return 0;
}

void Chairs::print_chairs() {
    string sql = "SELECT * FROM CHAIRS;";
    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql.c_str(), print_callback, nullptr, &errMsg) != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}
int Chairs::print_callback(void* NotUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << " ";
    }
    cout << endl;
    return 0;
}
void Chairs::order(Menu& menu,Stock& stock , string name){
    double price=menu.get_price(name);
    string amountts[5]={"MEAT", "CHICKEN", "POTATO", "TOMATO", "CHEESE"};
    for (int i=0; i<5; i++){
        string ingredient_name=amountts[i];
        double new_stock=stock.get_quantity(ingredient_name)-menu.get_amount(name, ingredient_name);
        stock.update_item(ingredient_name,new_stock);
    }
    int id=get_first_empty_chair_id();
    update_chair_price(id, price);
}
void Chairs::pay(Money& money, int id){
    double price=get_chair_price(id);
    if (price==0){cout<<"ERROR: NO PAYMENT"<<endl;}
    else{
        money.record_income(price);
        update_chair_price(id, 0);
    }
}