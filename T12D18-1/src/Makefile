CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
NAME = Quest_
BUILD_DIR = ../build

print_module: MACRO=PRINT_MODULE
documentation_module: MACRO=DOCUMENTATION_MODULE

all: print_module documentation_module bst_create_test bst_insert_test bst_traverse_test

print_module: main_module_entry_point.o print_module.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(NAME)1 $^

documentation_module: main_module_entry_point.o documentation_module.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(NAME)2 $^

bst_create_test: bst_create_test.o bst.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(NAME)3 $^

bst_insert_test: bst_insert_test.o bst.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(NAME)4 $^

bst_traverse_test: bst_traverse_test.o bst.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(NAME)5 $^

main_module_entry_point.o: main_module_entry_point.c
	$(CC) $(CFLAGS) -c $< -o $@ -D$(MACRO)

documentation_module.o: documentation_module.c
	$(CC) $(CFLAGS) -c $< -o $@

print_module.o: print_module.c
	$(CC) $(CFLAGS) -c $< -o $@

bst.o: bst.c
	$(CC) $(CFLAGS) -c $< -o $@

bst_create_test.o: bst_create_test.c
	$(CC) $(CFLAGS) -c $< -o $@

bst_insert_test.o: bst_insert_test.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o $(BUILD_DIR)/Quest_*

clean_build:
	rm *.o