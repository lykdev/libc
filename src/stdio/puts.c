#include <stdio.h>

#include <lykos/syscall.h>

int puts(const char *s)
{
    syscall1(SYSCALL_DEBUG_LOG, (uint64_t)s);

    while (*s != '\0')
        putchar(*s++);

    return 0;
}