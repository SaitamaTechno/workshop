#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>
using namespace std;
class Stock {
	
	public:
	    
	    Stock(string _name, int _quantity);
	
	    // Ürün miktarýný azaltan fonksiyon
	    void decreaseQuantity(int amount);
	
	    // Ürün miktarýný artýran fonksiyon
	    void increaseQuantity(int amount);
	
	    // Ürün adýný döndüren fonksiyon
	    string getProductName() ;
	
	    // Ürün miktarýný döndüren fonksiyon
	    int getQuantity() ;
	
	    // Stok durumunu ekrana yazan fonksiyon
	    void displayStock() const;
	    
	private:
	   string productName; 
	    int quantity;            
	
};

#endif // STOCK_H

