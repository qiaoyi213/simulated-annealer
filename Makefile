CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c99
LDFLAGS =

SRC_DIR = src
BIN_DIR = bin

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/matrix.c $(SRC_DIR)/sa.c $(SRC_DIR)/utils.c
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%.o,$(SRCS))

TARGET = $(BIN_DIR)/main

.PHONY: all clean debug

all: $(TARGET)

debug: CFLAGS += -g -DDEBUG
debug: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BIN_DIR)/*.o $(TARGET)
