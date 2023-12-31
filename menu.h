#ifndef MENU_H
#define MENU_H

#include <string>
#include <sqlite3.h>

using namespace std;

class Menu {
public:
    Menu(string filename);
    ~Menu();
    void add_menu_item(const string menu_name, double meat, double chicken, double tomato, double potato, double cheese);
    void update_menu_item(const string menu_name, const string ingredientName, double new_amount);
    void update_menu_price(const string menu_name, double new_price);
    void remove_menu_item(const string menu_name);
    void print_menu();
    void print_ingredients(const string name);
    double get_amount(const string menu_name, const string ingredientName);
    double get_price(const string menu_name);

private:
    sqlite3* db;
    static int callback(void* data, int argc, char** argv, char** azColName);
    static int callback1(void* data, int argc, char** argv, char** azColName);
    static int print_ingredients_callback(void* NotUsed, int argc, char** argv, char** azColName);
};

#endif
