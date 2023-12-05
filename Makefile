# Compiler and flags
CC := g++
CFLAGS := -Wall -Wextra -std=c++11
CXXFLAGS := -std=c++11
INC_DIR := include

# List of .cpp and .c files with relative paths
SRC_FILES := main.cpp \
	keygenlic.cpp \
	include/sha256/sha256.c \
	include/ed25519/verify.c \
	include/ed25519/keypair.c \
	include/ed25519/sign.c \
	include/ed25519/key_exchange.c \
	include/ed25519/sc.c \
	include/ed25519/ge.c \
	include/ed25519/add_scalar.c \
	include/ed25519/fe.c \
	include/ed25519/seed.c \
	include/ed25519/sha512.c

# Derive object file names from source files
OBJ_FILES := $(patsubst %.cpp, %.o, $(patsubst %.c, %.o, $(SRC_FILES)))

# Main target: build the library
TARGET := bin.out
LIB := libkeygenlic.a

# Build rule for the executable
$(TARGET): $(LIB)
	$(CC) $(CFLAGS) $^ -lssl -lcrypto -o $@

# Build rule for the library
$(LIB): $(OBJ_FILES)
	$(AR) rcs $@ $^

# Build rule for .cpp and .c files
%.o: %.cpp %.c $(INC_DIR)/%.h
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Phony target to clean the project
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJ_FILES)


