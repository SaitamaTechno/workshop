#include <iostream>
#include "Stock.h"
#include "Dish.h"
using namespace std;

int main()
{
	//main material
	AllStock Stocks;
	Stocks.display_data_by_name("Rice");
	Stock rice=Stocks.get_stock("Rice");
	
	//salmon.setQuantity(salmon.decreaseStock(salmon.getQuantity()));
	//cout << "salmon aded :" << salmon.getQuantity();
	
	
		//klasik roll
	Dish crunchyKuru("Crunchy Kuru Roll","Salmon, Cucumber, Potato Chips and Chizu sauce",rice, 240.00 );
	cout<<crunchyKuru.getName()<<endl;
	/*Dish crunchyEbi("Crunchy Ebi Roll","Tempura shrimp, Cucumber, Carrot Chips and Teriyaki sauce",248.00);
	Dish crunchyBakugan("Crunchy Bakugan Roll","Tempura Shrimp, Tofu, Asparagus, Carrot Chips and Teriyaki sauce",262.00);
	Dish kita("Kita Roll","Salmon, Avocado, Cucumber, Orenji Kurim sauce",282.00);
	Dish kinkunagi("Kinkunagi Roll","Caramelized Mushrooms, Asparagus, Avocado, Orenji Kurim sauce ",312.00);
	Dish tartare("Spicy Tartare Roll ","Spicy Salmon Tartare, Surimi Crab, Avocado, Cucumber, Chili Pepper and Chizu sauce",302.00);
	
	*/
		
	
}

