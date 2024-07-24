#include <iostream>
#include <string>
#include <memory>
#include <exception>
#include <algorithm>
#include <cstring>


// NAME:Ipv4\nDATA\0

class Message {

public:

    /* size standart package */
    static inline const size_t size_package = 255;

private:

    /* allocated memory */
    std::shared_ptr<char[255]> ptr;


    /* specify to ipv4 and data */
    char* ptr_ipv4;
    char* ptr_data;




public:
    Message(const Message& obj) = delete;

    Message(Message&& obj) = default;

    Message& operator=(const Message& obj) = delete;

    Message& operator=(Message&& obj) = default;


    Message() = default;

    Message(const char* name, const char* ipv4);


   // void set_name_ipv4(const char* name, const char* ipv4);

    char* get_data_ptr() const noexcept;

    const char* get_ipv4_ptr() const noexcept;

    const char* get_name_ptr() const noexcept;
};