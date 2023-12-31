#ifndef CHAIRS_H
#define CHAIRS_H

#include <sqlite3.h>
#include <string>
#include "menu.h"
#include "money.h"
#include "stock.h"
using namespace std;

class Chairs {
public:
    Chairs(string filename);
    ~Chairs();
    void add_chair(double price=0);
    void update_chair_price(int id, double newPrice);
    void delete_chair(int id);
    void print_chair_info(int id);
    void order(Menu& menu,Stock& stock, string name);
    void pay(Money& money, int id);
    int get_first_empty_chair_id();
    double get_chair_price(int id);
    void print_chairs();

private:
    sqlite3* db;
    static int next_id;
    static int callback(void *NotUsed, int argc, char **argv, char **azColName);
    static int single_id_callback(void* data, int argc, char** argv, char** azColName);
    static int single_double_callback(void* data, int argc, char** argv, char** azColName);
    static int print_callback(void* NotUsed, int argc, char** argv, char** azColName);

};

#endif 
