#include <string.h>

void *memmove(void *dest, const void *src, size_t n)
{
    char *d = (char*)dest;
    const char *s = (const char*)src;

    if (src > dest)
        while(n--)
            *d++ = *s++;
    else if (src < dest)
    {
        d += n, s += n;

        while(n--)
            *--d = *--s;
    }

    return dest;
}