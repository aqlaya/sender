#include <iostream>

#include "message.hpp"

int main() {

    std::string sender = "Misha:197.78.43.86\nI love you:\n";

    Message mess(std::move(sender));

    std::cout << mess.get_ipv4() << std::endl;
    std::cout << mess.get_name() << std::endl;


    std::cout << mess.get_ptr_to_data() << std::endl;

    return 0;
}