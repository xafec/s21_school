CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
BUILD = ../../build/
FILENAME1 = Quest_3
FILENAME2 = Quest_4
FILENAME3 = Quest_5
FILENAME4 = Quest_6

all: main clean_build

build_with_macro: main_executable_module_macro.o decision.o data_process.o data_stat.o
	$(CC) $(CFLAGS) $^ -o $(BUILD)$(FILENAME2)

build_with_static: decision.o data_process.o data_io.o data_stat.o data_stat.a main_executable_module.o
	$(CC) $(CFLAGS) main_executable_module.o decision.o data_process.o data_io.o -o $(BUILD)$(FILENAME3) data_stat.a

build_with_dynamic: decision.o data_io.o data_process.so main_executable_module.o
	$(CC) $(CFLAGS) main_executable_module.o decision.o data_io.o -o $(BUILD)$(FILENAME4) data_process.so

main: main_executable_module.o decision.o data_process.o data_io.o data_stat.o
	$(CC) $(CFLAGS) $^ -o $(BUILD)$(FILENAME1)

main_executable_module.o: main_executable_module.c
	$(CC) $(CFLAGS) -c main_executable_module.c

main_executable_module_macro.o: main_executable_module.c
	$(CC) $(CFLAGS) -DMACROS -c main_executable_module.c -o main_executable_module_macro.o

decision.o: ../yet_another_decision_module/decision.c
	$(CC) $(CFLAGS) -c ../yet_another_decision_module/decision.c

data_process.o: ../data_module/data_process.c
	$(CC) $(CFLAGS) -c ../data_module/data_process.c

data_process.so: ../data_module/data_process.c ../data_libs/data_stat.c
	$(CC) $(CFLAGS) -c -fPIC ../data_module/data_process.c
	$(CC) $(CFLAGS) -c -fPIC ../data_libs/data_stat.c
	$(CC) $(CFLAGS) -shared -o data_process.so data_process.o data_stat.o

data_io.o: ../data_libs/data_io.c
	$(CC) $(CFLAGS) -c ../data_libs/data_io.c

data_stat.a: data_stat.o
	ar rcs data_stat.a data_stat.o

data_stat.o: ../data_libs/data_stat.c
	$(CC) $(CFLAGS) -c ../data_libs/data_stat.c

clean_build:
	rm -rf *.o *.a

clean:
	rm -rf *.o *.a *.so $(BUILD)$(FILENAME1) $(BUILD)$(FILENAME2) $(BUILD)$(FILENAME3) $(BUILD)$(FILENAME4)

rebuild: clean all