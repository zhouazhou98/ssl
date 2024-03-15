#include <iostream>
#include "src/bio_base64.h"
#include <malloc.h>
#include <string.h>

int main(int argc, char ** argv) {
    const char * hello = "hello world!\n哈哈哈\nfewps,dlsjdker";

    std::cout << "size: " <<  strlen(hello) << "\n" << hello << std::endl << "-----------------" << std::endl;


    char * buf = (char *)malloc( sizeof(*buf) * (strlen(hello) * 2 + 1) );
    base64_encode((uint8_t *)hello, strlen(hello), buf);
    std::cout << "hello encode:\n" << "size: " <<  strlen(buf)  << std::endl << buf << std::endl;



    return 0;
}
