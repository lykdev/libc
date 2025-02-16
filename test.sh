#!/bin/bash

clang -ffreestanding -nostdlib -no-pie -g -o main.elf tests/main.c bin/libc.a -Iinc

