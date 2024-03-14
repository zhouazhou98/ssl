
#include <openssl/rand.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char ** argv) {
    unsigned char * buf = (unsigned char *)malloc(sizeof(unsigned char) * 10);
    RAND_bytes(buf, 10);
    printf("0x%x\n", buf[0]);


    return 0;
}