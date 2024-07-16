#pragma once

#include <iostream>
#include <string>
#include <cstring>

// MESSAGE
// NAME:IPV4\nDATA

class Message {
    private:

        std::string _data;
        const char* _ptr_name_and_ipv4 = nullptr;
        const char* _ptr_data = nullptr;

    public:
        Message(std::string&& inf);

        ~Message() = default;;

        Message(const Message& obj) = delete;
        Message& operator=(const Message& obj) = delete;

        Message(Message&& obj) = default; 

        Message& operator=(Message&& obj) = default;

        std::string get_ipv4();

        std::string get_name();

        auto get_ptr_to_data() -> const char*;

};


std::string Message::get_name() 
{
    return _data.substr(0, _data.find(':'));
}



std::string Message::get_ipv4() 
{
    return _data.substr(_data.find(':') + 1, _data.find('\n') - _data.find(':') - 1);
}


Message::Message(std::string&& inf): _data(std::move(inf))
{
    _ptr_name_and_ipv4 = _data.c_str();
    _ptr_data          = _data.c_str() + _data.find('\n') + 1;
}


auto  Message::get_ptr_to_data() -> const char *
{
    return _data.c_str() + _data.find('\n') + 1;
}
