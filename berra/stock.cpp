#include "stock.h"

using namespace std;


Stock::Stock(string _name, int _quantity)
	{
		productName = _name;
		quantity = _quantity;
	}


void Stock::decreaseQuantity(int amount) {
    if (amount <= quantity) {
        quantity -= amount;
        if (quantity<=2){
            cout<<"Quantity is low; ordering 10 more stock"<<endl;
            quantity+=10;
        }
    } else {
        
        cout << "Error: Not enough stock for " << productName << endl;
        
    }
}


void Stock::increaseQuantity(int amount) 
{
    quantity += amount;
}


string Stock::getProductName() 
{
    return productName;
}


int Stock::getQuantity()
 {
    return quantity;
}


void Stock::displayStock() const {
    cout << "Product: " << productName << ", Quantity: " << quantity << endl;
}

