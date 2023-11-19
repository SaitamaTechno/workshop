#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>
using namespace std;
class Stock {
	
	public:
	    
	    Stock(string _name, int _quantity);
	
	    // �r�n miktar�n� azaltan fonksiyon
	    void decreaseQuantity(int amount);
	
	    // �r�n miktar�n� art�ran fonksiyon
	    void increaseQuantity(int amount);
	
	    // �r�n ad�n� d�nd�ren fonksiyon
	    string getProductName() ;
	
	    // �r�n miktar�n� d�nd�ren fonksiyon
	    int getQuantity() ;
	
	    // Stok durumunu ekrana yazan fonksiyon
	    void displayStock() const;
	    
	private:
	   string productName; 
	    int quantity;            
	
};

#endif // STOCK_H

