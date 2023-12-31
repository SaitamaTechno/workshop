#ifndef MONEY_H
#define MONEY_H

#include <string>
#include <iostream>
#include <sqlite3.h>
using namespace std;

class Money {
public:
    Money(string filename);
    ~Money();
    void record_income(double amount);
    void record_expense(double amount);
    double get_balance() const;
    void print_transactions() const;
    friend ostream& operator<<(ostream& os, const Money& money);

private:
    static double s_balance;
    sqlite3* db;
    static int callback(void* NotUsed, int argc, char** argv, char** azColName);
    static int callback1(void *NotUsed, int argc, char **argv, char **azColName);

};

#endif
