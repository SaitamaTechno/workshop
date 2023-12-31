#include <iostream>
#include <string>
#include "sqlitee3.h"
#include "stock.h"
#include "money.h"
#include "menu.h"
#include "monthly_payment.h"
#include "chairs.h"
using namespace std;

int main_menu(){
    int option;
    cout << "--------------------------" << endl;
    cout << "\n--- Main Menu ---\n";
    cout << "1. Worker Interface" << endl;
    cout << "2. Customer Interface" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter option: ";
    cin >> option;
    return option;
}
int worker_interface(){
    int option;
    cout << "--------------------------" << endl;
    cout << "\n--- Worker Interface ---\n";
    cout << "1. Manage Workers" << endl;
    cout << "2. Manage Money" << endl;
    cout << "3. Manage Stock" << endl;
    cout << "4. Manage Monthly Payment" << endl;
    cout << "0. Return to Main Menu" << endl;
    cout << "Enter option: ";
    cin >> option;
    return option;
}
int client_interface(){
    int option;
    cout << "--------------------------" << endl;
    cout << "\n1. Display Menu" << endl;
    cout << "2. Place Order" << endl;
    cout << "3. Print Chairs" << endl;
    cout << "4. Pay for Order" << endl;
    cout << "5. Print Financial Status" << endl;
    cout << "0. Exit" << endl;

    cout << "Enter option: ";
    cin >> option;
    return option;
}
int manage_workers(){
    int option;
    cout << "--------------------------" << endl;
    cout << "\n--- Manage Workers ---\n";
    cout << "1. Print Worker Data\n";
    cout << "2. Add Worker\n";
    cout << "3. Delete Worker\n";
    cout << "4. Update Worker Salary\n";
    cout << "5. Update Worker Surname\n";
    cout << "6. Print All Workers\n";
    cout << "7. Print Worker By Full Name\n";
    cout << "0. Return to Worker Interface\n";
    cout << "Enter option: ";
    cin >> option;
    return option;
}
int moneyManagementMenu() {
    int option;
    cout << "--------------------------" << endl;
    cout << "\n--- Money Management ---\n";
    cout << "1. Record Income" << endl;
    cout << "2. Record Expense" << endl;
    cout << "3. Print All Transactions" << endl;
    cout << "4. Display Total Balance" << endl;
    cout << "5. Display Money Object ?_?" << endl;
    cout << "0. Return to Main Menu" << endl;
    cout << "Enter option: ";
    cin >> option;
    return option;
}
int stock_interface() {
    int option;
    cout << "--------------------------" << endl;
    cout << "\n--- Stock Management Interface ---\n";
    cout << "1. Add Stock Item" << endl;
    cout << "2. Get Quantity of an Item" << endl;
    cout << "3. Update Stock Item" << endl;
    cout << "4. Print Current Stock" << endl;
    cout << "0. Return to Main Menu" << endl;
    cout << "Enter option: ";
    cin >> option;
    return option;
}
int monthlyPaymentMenu() {
    int choice;
    cout << "--------------------------" << endl;
    cout << "\n--- Monthly Payment Management ---\n";
    cout << "1. Order Stocks for All Items\n";
    cout << "2. Order Specific Stock\n";
    cout << "3. Pay Salaries\n";
    cout << "4. Show Financial Status\n";
    cout << "0. Return to Main Menu\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

void addWorker(Sql& sql) {
    string firstName, lastName, position, address;
    int age, salary;

    cout << "Enter First Name: ";
    cin >> firstName;

    cout << "Enter Last Name: ";
    cin >> lastName;

    cout << "Enter Position: ";
    cin.ignore();  // Clear the input buffer before reading a line
    getline(cin, position);

    cout << "Enter Age: ";
    cin >> age;

    cin.ignore();  // Clear the input buffer before reading a line
    cout << "Enter Address: ";
    getline(cin, address);

    cout << "Enter Salary: ";
    cin >> salary;

    sql.add_worker(firstName, lastName, position, age, address, salary);
    cout << "Worker added successfully.\n";
}
void deleteWorker(Sql& sql) {
    int id;
    cout << "Enter Worker ID to delete: ";
    cin >> id;
    sql.delete_worker(id);
    cout << "Worker deleted successfully.\n";
}

void recordIncome(Money& money) {
    double amount;
    cout << "Enter Income Amount: ";
    cin >> amount;
    money.record_income(amount);
    cout << "Income recorded successfully.\n";
}
void recordExpense(Money& money) {
    double amount;
    cout << "Enter Expense Amount: ";
    cin >> amount;
    money.record_expense(amount);
    cout << "Expense recorded successfully.\n";
}
void printTransactions(Money& money) {
    money.print_transactions();
}
void getTotalBalance(Money& money) {
    cout << "Total Balance: " << money.get_balance() << endl;
}

void addStockItem(Stock& stock) {
    string item;
    int quantity;
    cout << "Enter item name: ";
    cin >> item;
    cout << "Enter quantity: ";
    cin >> quantity;
    stock.add_item(item, quantity);
    cout << "Item added successfully!\n";
}
void getStockItemQuantity(Stock& stock) {
    string item;
    cout << "Enter item name to check quantity: ";
    cin >> item;
    cout << "Quantity of " << item << ": " << stock.get_quantity(item) << endl;
}
void updateStockItem(Stock& stock) {
    string item;
    int quantity;
    cout << "Enter item name to update: ";
    cin >> item;
    cout << "Enter new quantity: ";
    cin >> quantity;
    stock.update_item(item, quantity);
    cout << "Item updated successfully!\n";
}
void printStock(Stock& stock) {
    stock.print_stock();
}

void orderAllStocks(MonthlyPayment& payment) {
    int quantity;
    cout << "Enter the quantity for each stock item: ";
    cin >> quantity;
    payment.order_stocks(quantity);
    cout << "Stocks ordered for all items.\n";
}
void orderSpecificStock(MonthlyPayment& payment) {
    string item;
    int quantity;
    double price;

    cout << "Enter stock item name: ";
    cin >> item;
    cout << "Enter quantity: ";
    cin >> quantity;
    cout << "Enter price per unit: ";
    cin >> price;

    payment.order_stock(item, quantity, price);
    cout << "Order placed for " << item << ".\n";
}
void payAllSalaries(MonthlyPayment& payment) {
    payment.pay_salaries();
    cout << "Salaries paid to all employees.\n";
}
void showFinancialStatus(MonthlyPayment& payment) {
    payment.show_financial_status();
}

int main(){
    Menu menu("mydata.db");
    Money money("mydata.db");
    Stock stock("mydata.db");
    Sql worker("mydata.db");
    Chairs chairs("mydata.db");

    MonthlyPayment payment(stock, money, worker);
    int option=-1;
    while (option!=0){
        option=main_menu();
        if (option==1){//Worker Interface
            while (option!=0){
                option=worker_interface();
                if (option==1){//Worker class
                    while (option!=0){
                        option=manage_workers();
                        if (option==6){
                            worker.print_all_workers();
                        }else if (option==2){
                            addWorker(worker);
                        }else if (option==3){
                            deleteWorker(worker);
                        }
                    }
                    option=-1;
                } else if (option==2){//Money class
                    while (option!=0){
                        option=moneyManagementMenu();
                        if (option==1){
                            recordIncome(money);
                        } else if (option==2){
                            recordExpense(money);
                        } else if (option==3){
                            printTransactions(money);
                        } else if (option==4){
                            getTotalBalance(money);
                        } else if (option==5){
                            cout<<money<<endl;
                        }
                    }
                    option=-1;
                } else if (option==3){//Stock class
                    while (option!=0){
                        option=stock_interface();
                        if (option==1){
                            addStockItem(stock);
                        } else if (option==2){
                            getStockItemQuantity(stock);
                        } else if (option==3){
                            updateStockItem(stock);
                        } else if (option==4){
                            printStock(stock);
                        }
                    }
                    option=-1;
                } else if (option==4){//monthly payment
                    while (option!=0){
                        option=monthlyPaymentMenu();
                        if (option==1){
                            orderAllStocks(payment);
                        } else if (option==2){
                            orderSpecificStock(payment);
                        } else if (option==3){
                            payAllSalaries(payment);
                        } else if (option==4){
                            showFinancialStatus(payment);
                        }
                    }
                    option=-1;
                }
            }
            option=-1;
        }
        else if(option==2){//Customer Interface
            while (option!=0){
                option=client_interface();
                if (option==1){//display menu
                    menu.print_menu();
                } else if (option==2){
                    string itemName;
                    cout << "Enter the menu item name to order: ";
                    cin.ignore(); // Clear the buffer
                    getline(cin, itemName);
                    chairs.order(menu, stock, itemName);
                    cout<<"\nOrder is Received!\n";
                } else if (option==3){
                    chairs.print_chairs();
                } else if (option==4){
                    int id;
                    cout<<"Enter chair id:";
                    cin>>id;
                    chairs.pay(money, id);
                    cout<<"\nPayment Successful!\n";
                } else if (option==5){
                    payment.show_financial_status();
                }
            }
            option=-1;
        }
    }
    return 0;
}
