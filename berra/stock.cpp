#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "stock.h"
using namespace std;


		
Stock::Stock(string n,int q)
{
	name = n;
	quantity= q;
}
Stock::~Stock(){}
		

void Stock::setQuantity(int q){quantity= q;}
void Stock::setName(int n){name= n;}
int Stock::getQuantity(){return quantity;}
string Stock::getName(){return name;}

int Stock::decreaseStock(int n)
{
	n=n-1;
	return n;
}
		
void Stock::addStock(int s)
{
	s=s+20;
			
}
AllStock::AllStock() {
    // Base ingredients
	Stock rice("Rice", 100);
	Stock nori("Nori", 100);
    append(rice);
    append(nori);

    // Fish or meat
    
}

void AllStock::append(Stock stock){
	stock_list.push_back(stock);
}
void AllStock::pop(){
	stock_list.pop_back();
}
vector<Stock> AllStock::get_list(){
	return stock_list;
}

void AllStock::display_data_by_name(string name){
	int a=0;
	for (int i=0; i<stock_list.size(); i++){
		if (name==stock_list[i].getName()){
			a=1;
			cout<<stock_list[i].getName()<<" : "<<stock_list[i].getQuantity()<<endl;
		}
	}
	if (a==0){cout<<name<<" is not registered!"<<endl;}
}
Stock AllStock::get_stock(string name){
	int a=0;
	for (int i=0; i<stock_list.size(); i++){
		if (name==stock_list[i].getName()){
			a=1;
			return stock_list[i];
		}
	}
	if (a==0){cout<<name<<" is not registered!"<<endl;}
}

