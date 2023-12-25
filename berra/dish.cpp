#include <iostream>
#include <string>
#include <vector>

#include "Dish.h"
#include "Stock.h"
using namespace std;
Dish::Dish(string n,string m,Stock a,int p)
{
	name = n;
	materials = m;
	price = p;
}
		
void Dish::setName(int n){name= n;}
void Dish::setMaterials(int m){materials= m;}
void Dish::setPrice(int p){price= p;}
string Dish::getName(){return name;}
string Dish::getMaterials(){return materials;}
double Dish::getPrice(){return price;}


