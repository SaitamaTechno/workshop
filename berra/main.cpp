#include "stock.h"

using namespace std;

int main() {
    
    Stock hamburgerMeat("Hamburger Meat", 10);
    Stock tomatoes("Tomatoes", 10);


    hamburgerMeat.displayStock();
    tomatoes.displayStock();

   
    hamburgerMeat.decreaseQuantity(1);
    tomatoes.decreaseQuantity(2);

    
    hamburgerMeat.displayStock();
    tomatoes.displayStock();

    
    Stock lettuce("Lettuce", 10);
    lettuce.displayStock();

   
    lettuce.increaseQuantity(5);
    lettuce.displayStock();

    
}

