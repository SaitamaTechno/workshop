#ifndef MONTHLYPAYMENT_H
#define MONTHLYPAYMENT_H

#include "stock.h"
#include "money.h"
#include "sqlitee3.h"
#include <string>
#include <vector>

using namespace std;

class MonthlyPayment {
public:
    MonthlyPayment(Stock& _stock, Money& _money, Sql& _worker);
    void order_stocks(int quantity);
    void pay_salaries();
    void show_financial_status();
    void order_stock(const string& item, int quantity, double price_per_unit);
    void update_stock(const string& item, int quantity);

private:
    Stock& stock;
    Money& money;
    Sql& worker;
    
};

#endif // MONTHLYPAYMENT_H
