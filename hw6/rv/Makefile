CC = clang
ARCH_FLAGS = --target=riscv32 -march=rv32i -mabi=ilp32
CFLAGS = -Wall -Wextra -Iinclude $(ARCH_FLAGS)
LDFLAGS = -nostdlib -T rv_link.ld $(ARCH_FLAGS)

CLIENT_C_SRC ?= 
CLIENT_S_SRC ?=

C_SRC = $(wildcard src/*.c) $(CLIENT_C_SRC)
S_SRC = $(wildcard src/*.s) $(CLIENT_S_SRC)

SRC = $(C_SRC) $(S_SRC)
OBJ = $(C_SRC:.c=.o) $(S_SRC:.s=.o) 

QEMU = qemu-riscv32

TARGET ?=

all: $(TARGET)

run: $(TARGET) 
	$(QEMU) ./$(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
