#include <iostream>

int main(){

    int itemPrice;
    itemPrice = 50;

    int shippingCost;
    shippingCost = 50;

    int sum;
    sum = itemPrice + shippingCost;

    std::cout << sum << "\n";
    std::cin.get();
    
    return 0;
}