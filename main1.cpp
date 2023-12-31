#include <iostream>
#include <string>
#include "sqlitee3.h"
#include "stock.h"
#include "money.h"
#include "menu.h"
#include "monthly_payment.h"
#include "chairs.h"
using namespace std;

int main(){
    Menu menu("mydata.db");
    Money money("mydata.db");
    Stock stock("mydata.db");
    Sql worker("mydata.db");
    Chairs chairs("mydata.db");

    MonthlyPayment payment(stock, money, worker);
    //money.record_income(100000);
    //payment.order_stocks(100); // orders every stock 100 kg and pays each
    //payment.pay_salaries();
    payment.show_financial_status();

    //chairs.order(menu, stock, "Classic Burger");
    chairs.pay(money, 2);
    chairs.print_chairs();
    //money.print_transactions();
    payment.show_financial_status();

    return 0;
}