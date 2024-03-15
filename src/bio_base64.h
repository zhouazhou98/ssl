#ifndef __ZHOU_BIO_BASE64_H__
#define __ZHOU_BIO_BASE64_H__


int base64_encode(const unsigned char * in, int len, char * base64);
int base64_decode(const char * in, int len, unsigned char * data);


#endif // ! __ZHOU_BIO_BASE64_H__