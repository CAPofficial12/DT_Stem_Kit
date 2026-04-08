#include <iostream>
#include <string>

int main(){

    std::string message;
    getline(std::cin , message);

    message = std::tolower(message);


    return 0;
}