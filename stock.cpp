#include "stock.h"
#include <iostream>

Stock::Stock(string filename){
    int rc=0;
    char *errorMessage = 0;
    rc = sqlite3_open(filename.c_str(), &db);
    if (rc != SQLITE_OK) {
      cerr << "SQL error: " << errorMessage << endl;
      sqlite3_free(errorMessage);
   }
}
Stock::~Stock(){
   sqlite3_close(db);
}
void Stock::add_item(string item_name, int quantity) {
    char* errMsg = nullptr;
    string sql = "INSERT INTO STOCK (ITEM_NAME, QUANTITY) VALUES ('" + item_name + "', " + to_string(quantity) + ");";
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}

void Stock::update_item(string item_name, int new_quantity) {
    char* errMsg = nullptr;
    string sql = "UPDATE STOCK SET QUANTITY = " + to_string(new_quantity) + " WHERE ITEM_NAME = '" + item_name + "';";
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}

void Stock::remove_item(string item_name) {
    char* errMsg = nullptr;
    string sql = "DELETE FROM STOCK WHERE ITEM_NAME = '" + item_name + "';";
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}

int Stock::get_quantity(string item_name) {
    int quantity = 0;
    char* errMsg = nullptr;
    string sql = "SELECT QUANTITY FROM STOCK WHERE ITEM_NAME = '" + item_name + "';";
    if (sqlite3_exec(db, sql.c_str(), Stock::callback1, &quantity, &errMsg) != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
    return quantity;
}

void Stock::print_stock() {
    char* errMsg = nullptr;
    string sql = "SELECT * FROM STOCK;";
    if (sqlite3_exec(db, sql.c_str(), Stock::callback, nullptr, &errMsg) != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}

int Stock::callback(void* NotUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
    }
    cout << endl;
    return 0;
}
int Stock::callback1(void* data, int argc, char** argv, char** azColName) {
    int* quantity = static_cast<int*>(data);
    if (argc > 0 && argv[0]) {
        *quantity = atoi(argv[0]);
    }
    return 0;
}

vector<string> Stock::get_stock_names() {
    vector<string> names;
    char* errMsg = nullptr;
    string sql = "SELECT DISTINCT ITEM_NAME FROM STOCK;"; // Assuming the column for names is 'ITEM_NAME'

    if (sqlite3_exec(db, sql.c_str(), names_callback, &names, &errMsg) != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }

    return names;
}

int Stock::names_callback(void* data, int argc, char** argv, char** azColName) {
    vector<string>* names = static_cast<vector<string>*>(data);
    if (argv[0]) {
        names->push_back(argv[0]);
    }
    return 0;
}
