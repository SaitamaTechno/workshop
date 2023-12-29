#ifndef MONEY_H
#define MONEY_H

#include <string>
#include <sqlite3.h>
using namespace std;

class Money {
public:
    Money(string filename);
    ~Money();
    void record_income(double amount);
    void record_expense(double amount);
    double get_balance();
    void print_transactions();

private:
    sqlite3* db;
    static int callback(void* NotUsed, int argc, char** argv, char** azColName);
};

#endif // MONEY_H
