CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: build

build: lib_grep.o s21_grep.o s21_grep

# Сборка объектных файлов хэдера
lib_grep.o: lib_grep.c
		$(CC) -c -o lib_grep.o lib_grep.c

# Сборка объ. исходника
s21_grep.o: s21_grep.c
		$(CC) -c -o s21_grep.o s21_grep.c

# Сборка исполняемого 
s21_grep: lib_grep.o s21_grep.o
		$(CC) $(CFLAGS) -o s21_grep lib_grep.o s21_grep.o

# Удаление *.о
clean:
		rm -rf *.o
		rm -rf *.out *.exe

clean_out:
		rm -rf s21_grep