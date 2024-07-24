#include "mess.hpp"

Message::Message(const char* name, const char* ipv4)
    : ptr( std::make_shared<char[255]>('\0') )
    , ptr_data(nullptr) 
    , ptr_ipv4(nullptr)
{
    std::copy(name, name + std::strlen(name), ptr.get());

    ptr[std::strlen(name)] = ':';

    std::copy(ipv4, ipv4 + std::strlen(ipv4), ptr.get() + std::strlen(name) + 1);

    ptr_ipv4 = std::find(ptr.get(), ptr.get() + 255, ':') + 1;

    ptr_data = std::find(ptr_ipv4, ptr.get() + 255, '\n') + 1;

    friend std::ostream& operator<<()
}

char* Message::get_data_ptr() const noexcept
{
    return ptr_data;
}

const char*  Message::get_ipv4_ptr() const noexcept
{
    return ptr_ipv4;
}

const char* Message::get_name_ptr() const noexcept
{
    return ptr.get();
}


