CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
BUILD_DIR = ../build/

all: state_sort clear_state

state_sort: state_sort.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)Quest_1 state_sort.c

state_search: state_search.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)Quest_2 state_search.c

clear_state: clear_state.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)Quest_3 clear_state.c

clean:
	rm -f $(BUILD_DIR)Quest_1 $(BUILD_DIR)Quest_3
