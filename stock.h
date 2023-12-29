#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <sqlite3.h>

using namespace std;

class Stock {
public:
    Stock(string filename);
    ~Stock();
    void add_item(string item_name, int quantity);
    void update_item(string item_name, int new_quantity);
    void remove_item(string item_name);
    int get_quantity(string item_name);
    void print_stock();

private:
    sqlite3* db;
    static int callback(void* NotUsed, int argc, char** argv, char** azColName);
    static int callback1(void* NotUsed, int argc, char** argv, char** azColName);
};

#endif // STOCK_H