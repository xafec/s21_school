CC = gcc
CFLAGS = -Wall -Wextra -Werror
BUILD_DIR = ../build/

all: clean clang-format logging_cipher cipher

logging_cipher: logger.c cipher.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)logging_cipher logger.c cipher.c

cipher: cipher.c logger.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)cipher cipher.c logger.c

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -f $(BUILD_DIR)cipher $(BUILD_DIR)logging_cipher

clang-format:
	cp ../materials/linters/.clang-format . && clang-format -i *.c *.h

.PHONY: all clean logging_cipher cipher