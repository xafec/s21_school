CC = gcc
CFLAGS = -Wall -Werror -Wextra
BUILD_DIR = ../build/

NAME1 = Quest_1
NAME2 = Quest_2
NAME3 = Quest_3

door_struct: dmanager_module.o
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)$(NAME1)

list_test: list_test.o list.o
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)$(NAME2)

stack_test: stack_test.o stack.o
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)$(NAME3)

dmanager_module.o: dmanager_module.c
	$(CC) $(CFLAGS) -c $^ -o $@

list_test.o: list_test.c
	$(CC) $(CFLAGS) -c $^ -o $@

list.o: list.c
	$(CC) $(CFLAGS) -c $^ -o $@

stack_test.o: stack_test.c
	$(CC) $(CFLAGS) -c $^ -o $@

stack.o: stack.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm *.o *.a *.s $(BUILD_DIR)$(NAME1) $(BUILD_DIR)$(NAME2) $(BUILD_DIR)$(NAME3)