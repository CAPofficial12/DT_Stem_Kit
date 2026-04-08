#include <iostream>
#include <string>

int main(){

    std::string message;
    std::string new_message;

    getline(std::cin , message);

    for (char i: message){
        char a = std::tolower((unsigned char)i);
        new_message = new_message + a;
    }

    std::cout << new_message;
    std::cin.get();
    return 0;
}