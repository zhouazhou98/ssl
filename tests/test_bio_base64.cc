#include <iostream>
#include "src/bio_base64.h"
#include <malloc.h>
#include <string.h>

int main(int argc, char ** argv) {
    const char * hello = "hello world!\n哈哈哈\nfewps,dlsjdkerinjsnfksmlkj";

    std::cout << "size: " <<  strlen(hello) << "\n" << hello << std::endl << "-----------------" << std::endl;


    char * buf = (char *)malloc( sizeof(*buf) * (strlen(hello) * 2 + 1) );
    int encode_length = base64_encode((uint8_t *)hello, strlen(hello), buf);
    std::cout << "hello encode:\n" << "size: " <<  strlen(buf)  << std::endl << buf << std::endl;

    
    unsigned char buf2[1024] = { 0 };
    base64_decode(buf, encode_length, buf2);
    std::cout << "decode:\n" << buf2 << std::endl;


    return 0;
}
