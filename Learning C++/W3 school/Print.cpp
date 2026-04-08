#include<iostream>

int main()
{
    int a =5;

    std::cout << a;
    std::cout << "Hello World" << std::endl;
    std::cout << "The endl moves the print function to the next line" << std::endl;

    int value {100};
    std::cout << value << std::endl;

    int value2 (100.7);
    std::cout << value2 << std::endl;

    std::string name;
    std::cin >> name;

    std::cout << name << std::endl;

    std::cin.get();
    return 0;
}