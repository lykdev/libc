LIBC_A   := bin/libc.a
LIBC_SO  := bin/libc.so
CRT0_OBJ := bin/$(ARCH)/crt0.o

# TOOLCHAIN

CC = clang
LD = ld.lld
AR = llvm-ar

# COMPILER FLAGS

C_FLAGS :=                     \
	-Wall                      \
	-Wextra                    \
	-ffreestanding             \
	-fPIC                      \
	-O2                        \
	-g                         \
	-I inc                     \
	-std=gnu23                 \
	-fvisibility=hidden

LD_FLAGS :=                     \
	-nostdlib                   \
	-static                     \
	-gc-sections

AS_FLAGS :=                     \
	-fPIC

# ARCH-SPECIFIC COMPILER FLAGS

ifeq ($(ARCH), x86_64)
	C_FLAGS +=                        \
		-target x86_64-elf            \
		-m64                          \
		-mno-red-zone

	LD_FLAGS +=                       \
		-m elf_x86_64
else ifeq ($(ARCH), aarch64)
	C_FLAGS +=                        \
		-target aarch64-unknown-none

	LD_FLAGS +=                       \
		-m aarch64elf
     
	AS_FLAGS +=                       \
		-target aarch64-unknown-none
endif

# OBJECTS

C_FILES   := $(shell cd src && find -L * -type f -name '*.c')
AS_FILES  := $(shell cd src && find -L * -type f -name '*.S')
OBJ_FILES := $(addprefix obj/, $(C_FILES:.c=.c.o) $(AS_FILES:.S=.S.o))

# BUILDING

.PHONY: all clean
all: $(LIBC_A) $(LIBC_SO)

$(LIBC_A): $(CRT0_OBJ) $(OBJ_FILES)
	mkdir -p $(@D)
	$(AR) rcs $@ $^

$(LIBC_SO): $(OBJ_FILES)
	mkdir -p $(@D)
	$(LD) $(LD_FLAGS) -shared -o $@ $^

$(CRT0_OBJ): crt/$(ARCH)/crt0.S
	mkdir -p $(@D)
	$(CC) $(AS_FLAGS) -c -o $@ $<

obj/%.c.o: src/%.c
	mkdir -p $(@D)
	$(CC) $(C_FLAGS) -c -o $@ $<

obj/%.S.o: src/%.S
	mkdir -p $(@D)
	$(CC) $(AS_FLAGS) -c -o $@ $<

clean:
	rm -rf obj bin *.elf
