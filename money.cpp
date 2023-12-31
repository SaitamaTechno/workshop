#include "money.h"
#include <iostream>
#include <cmath>
double Money::s_balance = 0.0;

Money::Money(string filename){
    int rc=0;
    char *errorMessage = 0;
    rc = sqlite3_open(filename.c_str(), &db);
    if (rc != SQLITE_OK) {
      cerr << "SQL error: " << errorMessage << endl;
      sqlite3_free(errorMessage);
   }
}
Money::~Money(){
   sqlite3_close(db);
}
void Money::record_income(double amount) {
    char* errMsg = nullptr;
    string sql = "INSERT INTO FINANCES (TYPE, AMOUNT) VALUES ('Income', " + to_string(amount) + ");";
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}

void Money::record_expense(double amount) {
    char* errMsg = nullptr;
    string sql = "INSERT INTO FINANCES (TYPE, AMOUNT) VALUES ('Expense', " + to_string(amount) + ");";
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}

double Money::get_balance() const{
    s_balance = 0.0; // Reset balance
    char* errMsg = nullptr;
    string sql = "SELECT TYPE, AMOUNT FROM FINANCES;";

    if (sqlite3_exec(db, sql.c_str(), Money::callback, nullptr, &errMsg) != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }

    return s_balance;
}


void Money::print_transactions() const{
    char* errMsg = nullptr;
    string sql = "SELECT * FROM FINANCES;";
    if (sqlite3_exec(db, sql.c_str(), Money::callback1, nullptr, &errMsg) != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}
int Money::callback1(void *NotUsed, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << endl;
    }
    cout << endl;
    return 0;
}
int Money::callback(void* NotUsed, int argc, char** argv, char** azColName) {
    string type = argv[0];
    double amount = stod(argv[1]);

    if (type == "Income") {
        s_balance += amount;
    } else if (type == "Expense") {
        s_balance -= amount;

    }

    return 0;
}
ostream& operator<<(ostream& os, const Money& money) {
    money.print_transactions();
    os << "\nBalance: " <<money.get_balance();
    return os;
}