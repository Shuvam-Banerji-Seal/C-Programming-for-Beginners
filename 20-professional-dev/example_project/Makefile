# Example Project Makefile

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I$(INC_DIR)
LDLIBS = -lm

SRC_DIR = src
LIB_DIR = lib
INC_DIR = include
BUILD_DIR = build
BIN_DIR = bin
TEST_DIR = tests

PREFIX ?= /usr/local
BINDIR = $(PREFIX)/bin

DEBUG ?= 0
ifeq ($(DEBUG), 1)
CFLAGS += -g -O0 -DDEBUG
else
CFLAGS += -O2 -DNDEBUG
endif

TARGET = $(BIN_DIR)/math_example
LIB_TARGET = $(BUILD_DIR)/libmathutils.a
TEST_TARGET = $(BUILD_DIR)/test_math

APP_SRCS = $(wildcard $(SRC_DIR)/*.c)
LIB_SRCS = $(wildcard $(LIB_DIR)/*.c)
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)

APP_OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(APP_SRCS))
LIB_OBJS = $(patsubst $(LIB_DIR)/%.c,$(BUILD_DIR)/lib_%.o,$(LIB_SRCS))
TEST_OBJS = $(patsubst $(TEST_DIR)/%.c,$(BUILD_DIR)/test_%.o,$(TEST_SRCS))

all: $(TARGET)
@echo "Build complete!"

$(TARGET): $(APP_OBJS) $(LIB_TARGET)
@mkdir -p $(BIN_DIR)
$(CC) -o $@ $(APP_OBJS) $(LIB_TARGET) $(LDLIBS)

$(LIB_TARGET): $(LIB_OBJS)
@mkdir -p $(BUILD_DIR)
ar rcs $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
@mkdir -p $(BUILD_DIR)
$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/lib_%.o: $(LIB_DIR)/%.c
@mkdir -p $(BUILD_DIR)
$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/test_%.o: $(TEST_DIR)/%.c
@mkdir -p $(BUILD_DIR)
$(CC) $(CFLAGS) -c $< -o $@

$(TEST_TARGET): $(TEST_OBJS) $(LIB_TARGET)
$(CC) -o $@ $(TEST_OBJS) $(LIB_TARGET) $(LDLIBS)

test: $(TEST_TARGET)
@echo "Running tests..."
@$(TEST_TARGET)

clean:
rm -rf $(BUILD_DIR) $(BIN_DIR)

run: $(TARGET)
$(TARGET)

.PHONY: all test clean run
