CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: build

build: cat_lib.o s21_cat.o s21_cat

cat_lib.o: cat_lib.c
		$(CC) -c -o cat_lib.o cat_lib.c

s21_cat.o: s21_cat.c
		$(CC) -c -o s21_cat.o s21_cat.c
s21_cat: cat_lib.o s21_cat.o
		$(CC) $(CFLAGS) -o s21_cat cat_lib.o s21_cat.o

clean:
		rm -rf *.o