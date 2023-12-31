#include "menu.h"
#include <iostream>
#include <cmath>

Menu::Menu(string filename) {
    int rc = sqlite3_open(filename.c_str(), &db);
    if (rc != SQLITE_OK) {
        cerr << "Error opening SQLite3 database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
    }
}

Menu::~Menu() {
    sqlite3_close(db);
}

void Menu::add_menu_item(const string menu_name, double meat, double chicken, double tomato, double potato, double cheese) {
    double price_per_unit = 10.0 * 1.5;  // %50 profit
    double price=0;
    double amountts[5]={meat, chicken, potato, tomato, cheese};
    for (int i=0; i<5; i++){
        price_per_unit*=1.05;
        price+=amountts[i]*price_per_unit;
    }
    price = round(price * 100) / 100;
    string sql = "INSERT INTO MENU (MENU_NAME, PRICE, MEAT, CHICKEN, TOMATO, POTATO, CHEESE) VALUES ('" +
                 menu_name + "', " + to_string(price) + ", " + to_string(meat) + ", " +
                 to_string(chicken) + ", " + to_string(tomato) + ", " + to_string(potato) + ", " +
                 to_string(cheese) + ");";
    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}

void Menu::update_menu_item(const string menu_name, const string ingredientName, double new_amount) {
    string sql = "UPDATE MENU SET " + ingredientName + " = " + to_string(new_amount) +
                 " WHERE MENU_NAME = '" + menu_name + "';";

    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}
void Menu::update_menu_price(const string menu_name, double new_price) {
    string sql = "UPDATE MENU SET PRICE = " + to_string(new_price) +
                 " WHERE MENU_NAME = '" + menu_name + "';";
    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }}
void Menu::remove_menu_item(const string menu_name) {
    string sql = "DELETE FROM MENU WHERE MENU_NAME = '" + menu_name + "';";

    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}

double Menu::get_amount(const string menu_name, const string ingredientName) {
    double amount = 0.0;
    string sql = "SELECT " + ingredientName + " FROM MENU WHERE MENU_NAME = '" + menu_name + "';";

    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql.c_str(), Menu::callback1, &amount, &errMsg) != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
    return amount;
}
double Menu::get_price(const string menu_name) {
    double price = 0.0;
    string sql = "SELECT PRICE FROM MENU WHERE MENU_NAME = '" + menu_name + "';";
    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql.c_str(), Menu::callback1, &price, &errMsg) != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }    
    return price;
}
void Menu::print_menu() {
    string sql = "SELECT * FROM MENU;";

    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql.c_str(), Menu::callback, nullptr, &errMsg) != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}

int Menu::callback(void* data, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
    }
    cout << endl;
    return 0;
}

int Menu::callback1(void* data, int argc, char** argv, char** azColName) {
    double* amount = static_cast<double*>(data);
    if (argc > 0 && argv[0]) {
        *amount = stod(argv[0]);
    }
    return 0;
}
void Menu::print_ingredients(const string name) {
    char* errMsg = nullptr;
    string sql = "SELECT * FROM MENU WHERE menu_name = '" + name + "';";
    if (sqlite3_exec(db, sql.c_str(), Menu::print_ingredients_callback, nullptr, &errMsg) != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}
int Menu::print_ingredients_callback(void* NotUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        if (i == 0) {  // Assuming the first column is 'menu_name'
            cout << "Menu Item: " << (argv[i] ? argv[i] : "Unknown") << endl;
        } else {
            cout << azColName[i] << ": " << (argv[i] ? argv[i] : "0") << endl;
        }
    }
    cout << endl;
    return 0;
}