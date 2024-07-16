#include <iostream>
#include "message.hpp"
#include "threadsafe_queue.hpp"

int main() {
    std::cout << "Hello";


    threadsafe_queue<Message> qu;

    std::string str =  "MISHA:123.456.12.12\nHello, friend";
    std::string str_2 = "TANYA:123.456.12.12\nI love you";
    Message message(std::move(str));
    Message message_2(std::move(str_2));
    qu.try_pop();
    qu.push(std::move(message));
    qu.push(std::move(message_2));
    
}