CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
BUILD = ../build/
NAME1 = Quest_1
NAME2 = Quest_2
NAME3 = Quest_3
NAME4 = Quest_4
NAME5 = Quest_5
NAME6 = Quest_6
NAME8 = Quest_8

strlen_tests: MACRO=STRLEN
strcmp_tests: MACRO=STRCMP
strcpy_tests: MACRO=STRCPY
strcat_tests: MACRO=STRCAT
strchr_tests: MACRO=STRCHR
strstr_tests: MACRO=STRSTR

strlen_tests: s21_string.o s21_string_test.o
	$(CC) $(CFLAGS) $^ -o $(BUILD)$(NAME1)

strcmp_tests: s21_string.o s21_string_test.o
	$(CC) $(CFLAGS) $^ -o $(BUILD)$(NAME2)

strcpy_tests: s21_string.o s21_string_test.o
	$(CC) $(CFLAGS) $^ -o $(BUILD)$(NAME3)

strcat_tests: s21_string.o s21_string_test.o
	$(CC) $(CFLAGS) $^ -o $(BUILD)$(NAME4)

strchr_tests: s21_string.o s21_string_test.o
	$(CC) $(CFLAGS) $^ -o $(BUILD)$(NAME5)

strstr_tests: s21_string.o s21_string_test.o
	$(CC) $(CFLAGS) $^ -o $(BUILD)$(NAME6)

s21_string.o: s21_string.c
	$(CC) $(CFLAGS) -c s21_string.c

s21_string_test.o: s21_string_test.c
	$(CC) $(CFLAGS) -D$(MACRO) -c s21_string_test.c

clean_build:
	rm -rf *.o *.a

clean:
	rm -rf *.o *.a *.so $(BUILD)$(NAME1) $(BUILD)$(NAME2) $(BUILD)$(NAME3) $(BUILD)$(NAME4) $(BUILD)$(NAME5) $(BUILD)$(NAME6) $(BUILD)$(NAME8)