#include <string>
#include <vector>
#include <iostream>
#include "stock.h"
#ifndef  DISH_H
#define DISH_H

using namespace std;
class Dish
{
	private :
		string name;
		string materials;
		double price;
		
	
	public:
		Dish(string n,string m,Stock a, int p);
		void setName(int n);
		void setMaterials(int m);
		void setPrice(int p);
		string getName();
		string getMaterials();
		double getPrice();
};




#endif
