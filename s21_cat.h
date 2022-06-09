#ifndef SRC_S21_CAT_H
#define SRC_S21_CAT_H
#include <stdio.h>
#include <getopt.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef struct flag {
    int b;
    int e;
    int n;
    int s;
    int t;
    int v;
} opts;

int pars(int argc, char *argv[], opts *flag);
int file_processing(char *argv[], opts *flg);

#endif  // SRC_S21_CAT_H_
