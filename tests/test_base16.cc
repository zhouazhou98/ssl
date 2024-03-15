#include <iostream>
#include "src/base16.h"
#include <malloc.h>
#include <string.h>

int main(int argc, char ** argv) {
    const char * hello = "hello world!\n哈哈哈\nfewps,dlsjdker";

    std::cout << "size: " <<  strlen(hello) << "\n" << hello << std::endl << "-----------------" << std::endl;


    char * buf = (char *)malloc( sizeof(*buf) * (strlen(hello) * 2 + 1) );
    base16_encode((uint8_t *)hello, strlen(hello), buf);
    std::cout << "hello encode:\n" << "size: " <<  strlen(buf)  << std::endl << buf << std::endl;


    char * buf2 = (char *)malloc( (strlen(hello) * 2 + 1) );
    base16_decode(buf, strlen(buf), (uint8_t *)buf2);
    std::cout << buf2 << std::endl;

    return 0;
}
