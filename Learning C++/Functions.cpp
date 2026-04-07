#include <iostream>

const age {5};

int GetValueFromUser()
{
    std::cout << "Enter an Integer: \n";
    int value;
    std::cin >> value;

    return value;
}

int main()  // Main must always return an integer
{
    int interger {GetValueFromUser()};
    std::cout << "The number " << interger << " doubled is " << interger * 2 << "\n";
    return 0;
}