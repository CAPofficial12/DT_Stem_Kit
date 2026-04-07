#include <iostream>

int GetValueFromUser()
{
    std::cout << "Enter an Integer: ";
    int value;
    std::cin >> value;

    return value;
}

int main()  // Main must always return an integer
{
    int interger {GetValueFromUser()};
    std::cout << "The number " << interger << " doubled is " << interger * 2 << std::endl;
    return 0;
}