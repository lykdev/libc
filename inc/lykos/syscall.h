#ifndef _SYSCALL_H
#define _SYSCALL_H 1

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum
{
    SYSCALL_EXIT      = 0,
    SYSCALL_DEBUG_LOG = 1
}
syscall_code_t;

uint64_t syscall0(uint64_t code);
uint64_t syscall1(uint64_t code, uint64_t arg1);
uint64_t syscall2(uint64_t code, uint64_t arg1, uint64_t arg2);
uint64_t syscall3(uint64_t code, uint64_t arg1, uint64_t arg2, uint64_t arg3);
uint64_t syscall4(uint64_t code, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4);
uint64_t syscall5(uint64_t code, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5);
uint64_t syscall6(uint64_t code, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6);

#ifdef __cplusplus
};
#endif

#endif /* _SYSCALL_H */