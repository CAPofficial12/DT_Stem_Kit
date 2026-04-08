#include <iostream>
#include <string>

int main(){

    std::string message;
    std::string new_message;

    getline(std::cin, message);

    for (char c: message){

        std::string a = "...";
        
        if (c != ' ' ){
            a = c;
        }

        new_message += a;
    }

    std::cout << new_message;
    std::cin.get();

    return 0;
}