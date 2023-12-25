
#ifndef  STOCK_H
#define STOCK_H

#include <string>
#include <vector>

using namespace std;
class Stock
{
	public :
		string name;
		int quantity;
	
	public:
		Stock(string n,int q);
		~Stock();
		int decreaseStock(int n);
		void addStock(int s);
		void setQuantity(int q);
		void setName(int n);
		int getQuantity();
		string getName();
		
};

class AllStock{
	private:
		vector<Stock> stock_list;
	public:
		AllStock();
		void append(Stock stock);
		void pop();
		void pop_by_name(string _name);
		void display_list();
		void display_data_by_name(string name);
		void update_stock(Stock stock);
		vector<Stock> get_list();
		Stock get_stock(string name);
};
#endif
