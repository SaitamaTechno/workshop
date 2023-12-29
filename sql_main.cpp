#include <iostream>
#include <string>
#include "sqlitee3.h"
#include "stock.h"
#include "money.h"
#include "menu.h"

using namespace std;

int main(){
    //              SQL MANAGE WORKERS              //
    //Sql sql("mydata.db");
    //sql.print_worker_data(1);
    //sql.add_worker("üğşiçö.iü", "Telli", "boss", 21, "123 Main St", 1000);
    //sql.delete_worker(3);
    //sql.add_worker("Mikasa", "Ackerman", "cooker", 21, "123 Main St", 500);
    //sql.update_worker(1, "SALARY", 5000); //overloading
    //sql.update_worker(2, "SURNAME", "Jaeger");
    //sql.print_all_workers();
    //sql.print_worker_by_fullname("Mikasa Jaeger");

    //              SQL MANAGE STOCKS               //
    //Stock stock("mydata.db");
    //stock.add_item("meat", 99);
    //stock.add_item("tomato", 100);
    //cout<<stock.get_quantity("meat")<<endl;
    //stock.update_item("meat", 101);
    //stock.print_stock();

    //              SQL MANAGE MONEY                //
    Money money("mydata.db");
    //money.record_income(10000);
    money.record_expense(1000);
    money.print_transactions();
    cout<<"Total Balance: "<<money.get_balance()<<endl;

    //              SQL MANAGE MENU                 //
    Menu menu("mydata.db");
    //menu.add_menu_item("Chicken Burger", 0.0, 0.2, 0.1, 0.0, 0.0);
    //menu.add_menu_item("Cheese Burger", 0.1, 0.0, 0.05, 0.0, 0.05);
    //menu.add_menu_item("Veggie Burger", 0.0, 0.0, 0.1, 0.1, 0.05);
    //menu.add_menu_item("Classic Burger", 0.15, 0.0, 0.05, 0.0, 0.05);
    //menu.print_ingredients("Chicken Burger");
    menu.print_menu();
    return 0;
}