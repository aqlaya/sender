#include "mess.hpp"


int main() {

    const char* str = "Help in my";

    Message mess("MISHA", "127.0.0.1" );
    char* ptr = mess.get_data_ptr();

    for (int i = 0; str[i] != '\0'; ++i)
    {
        ptr[i] = str[i];
    }

}
