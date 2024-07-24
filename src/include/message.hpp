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

        Message() = default;

        Message(std::string&& inf);

        ~Message() = default;;

        Message(const Message& obj) = default;
        Message& operator=(const Message& obj) = default;

        Message(Message&& obj) = default; 

        Message& operator=(Message&& obj) = default;

        std::string get_ipv4() const;

        std::string get_name() const ;

        auto get_ptr_to_data() const  ->  const char* ;

        void get_data(const char*);

    friend std::ostream& operator<<(std::ostream&, const Message& obj);

};


