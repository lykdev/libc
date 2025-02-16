#include "string.h"

void *memcpy(void *__restrict dest, const void *__restrict src, size_t n)
{
    char *d = (char*)dest;
    const char *s = (char*)src;

    while(n--)
        *d++ = *s++;

    return dest;
}