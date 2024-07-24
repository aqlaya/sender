#include "message.hpp"

std::ostream& operator<<(std::ostream& stream, const Message& obj) {
    stream << obj._data << "\n";
    return stream;
}

void Message::get_data(const char* raw_ptr) {
    _data = std::string(raw_ptr);

    _ptr_name_and_ipv4 = _data.c_str();
    _ptr_data          = _data.c_str() + _data.find('\n') + 1;
}


std::string Message::get_name() const 
{
    if (!_data.empty())
        return _data.substr(0, _data.find(':'));
    else
        return std::string();
}



std::string Message::get_ipv4() const
{
    if (!_data.empty())
        return _data.substr(_data.find(':') + 1, _data.find('\n') - _data.find(':') - 1);
    else
        return std::string();
}


Message::Message(std::string&& inf): _data(std::move(inf))
{
    _ptr_name_and_ipv4 = _data.c_str();
    _ptr_data          = _data.c_str() + _data.find('\n') + 1;
}


auto  Message::get_ptr_to_data() const  -> const char* 
{
    if (!_data.empty())
        return _data.c_str() + _data.find('\n') + 1;
    else
        return nullptr;
}
