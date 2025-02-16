#include <lykos/syscall.h>

#define SYSCALL(...)                            \
    uint64_t ret;                               \
    asm volatile("syscall"                      \
        : "=a" (ret)                            \
        : __VA_ARGS__                           \
        : "rcx", "r11", "memory"                \
    );                                          \
    return ret;

uint64_t syscall0(uint64_t sc)
{
    SYSCALL("a"(sc));
}

uint64_t syscall1(uint64_t sc, uint64_t arg1)
{
    SYSCALL("a"(sc), "D"(arg1));
}

uint64_t syscall2(uint64_t sc, uint64_t arg1, uint64_t arg2)
{
    SYSCALL("a"(sc), "D"(arg1), "S"(arg2));
}

uint64_t syscall3(uint64_t sc, uint64_t arg1, uint64_t arg2, uint64_t arg3)
{
    SYSCALL("a"(sc), "D"(arg1), "S"(arg2), "d"(arg3));
}

uint64_t syscall4(uint64_t sc, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4)
{
    register uint64_t arg4_reg asm("r10") = arg4;
    SYSCALL("a"(sc), "D"(arg1), "S"(arg2), "d"(arg3), "r"(arg4_reg));
}

uint64_t syscall5(uint64_t sc, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5)
{
    register uint64_t arg4_reg asm("r10") = arg4;
    register uint64_t arg5_reg asm("r8") = arg5;
    SYSCALL("a"(sc), "D"(arg1), "S"(arg2), "d"(arg3), "r"(arg4_reg), "r"(arg5_reg));
}

uint64_t syscall6(uint64_t sc, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6)
{
    register uint64_t arg4_reg asm("r10") = arg4;
    register uint64_t arg5_reg asm("r8") = arg5;
    register uint64_t arg6_reg asm("r9") = arg6;
    SYSCALL("a"(sc), "D"(arg1), "S"(arg2), "d"(arg3), "r"(arg4_reg), "r"(arg5_reg), "r"(arg6_reg));
}