#include "money.h"
#include <iostream>

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
    std::string sql = "INSERT INTO FINANCES (TYPE, AMOUNT) VALUES ('Income', " + std::to_string(amount) + ");";
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

void Money::record_expense(double amount) {
    char* errMsg = nullptr;
    std::string sql = "INSERT INTO FINANCES (TYPE, AMOUNT) VALUES ('Expense', " + std::to_string(amount) + ");";
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

double Money::get_balance() {
    double balance = 0.0;
    char* errMsg = nullptr;
    std::string sql = "SELECT TYPE, AMOUNT FROM FINANCES;";
    if (sqlite3_exec(db, sql.c_str(), [](void* data, int argc, char** argv, char** azColName) -> int {
        double* balance = static_cast<double*>(data);
        std::string type = argv[0];
        double amount = std::stod(argv[1]);
        if (type == "Income") {
            *balance += amount;
        } else if (type == "Expense") {
            *balance -= amount;
        }
        return 0;
    }, &balance, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
    return balance;
}

void Money::print_transactions() {
    char* errMsg = nullptr;
    std::string sql = "SELECT * FROM FINANCES;";
    if (sqlite3_exec(db, sql.c_str(), Money::callback, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

int Money::callback(void* NotUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
