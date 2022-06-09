#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_
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

int flags(int argc, char *argv[], opts *flag);
int read_file(char *argv[], opts *flg);

#endif  // SRC_CAT_S21_CAT_H_
