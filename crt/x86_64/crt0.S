.section .text

.global _start
_start:
    # Call main(argc, argv).
    # pop %rdi        # argc (first argument).
    # mov %rsp, %rsi  # argv (second argument).
    call main

    # Exit (syscall 0, exit code in %rdi).
    mov %rax, %rdi  # Move main's return value to %rdi.
    mov $0, %rax    # Syscall number 0 (exit).
    syscall
