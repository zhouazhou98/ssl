#ifndef __ZHOU_BASE16_H__
#define __ZHOU_BASE16_H__
#include <stdint.h>

int base16_encode(const uint8_t * raw, int len, char * buf);

int base16_decode(const char * raw, int len, uint8_t * buf);

#endif  // ! __ZHOU_BASE16_H__