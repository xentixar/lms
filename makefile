# Makefile for Raylib project

# Compiler
CC = gcc
RAYLIB_DIR = /home/xentixar/c_projects/raylib/build
BIN = bin
BUILD = build
INCLUDE = include
SOURCE = src

# Compiler flags
CFLAGS = -Wall -I$(RAYLIB_DIR)/raylib/include -L$(RAYLIB_DIR)/raylib/ -l:libraylib.a -lm -lpthread -ldl -lrt -lX11

# Source files
SRC = $(SOURCE)/main.c

# Executable name
EXE = $(BIN)/lms

# Build target
all: $(SRC)
	$(CC) $(SRC) -o $(EXE) $(CFLAGS)

# Clean target
clean:
	rm -f $(EXE)

run: all
	./$(EXE)
