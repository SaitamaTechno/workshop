#include <iostream>
#include "monthly_payment.h"

MonthlyPayment::MonthlyPayment(Stock& _stock, Money& _money, Sql& _worker) 
    : stock(_stock), money(_money), worker(_worker) {
}

void MonthlyPayment::order_stock(const string& item, int quantity, double price_per_unit) {
    double cost = quantity * price_per_unit;
    money.record_expense(cost);
    stock.update_item(item, stock.get_quantity(item) + quantity);
}
void MonthlyPayment::order_stocks(int quantity) {
    vector<string> stockNames = stock.get_stock_names();
    double price_per_unit = 10.0;

    for (const string& item : stockNames) {
        price_per_unit*=1.1;
        order_stock(item, quantity, price_per_unit);
    }
}

void MonthlyPayment::pay_salaries() {
    double totalSalaryAmount = worker.get_total_salaries();
    money.record_expense(totalSalaryAmount);
}

void MonthlyPayment::show_financial_status(){
    cout<<"Balance: "<<money.get_balance()<<endl;
}

void MonthlyPayment::update_stock(const string& item, int quantity) {
    stock.update_item(item, quantity);
}
