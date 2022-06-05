#include <stdio.h>
#include<unistd.h>
#include "lib_grep.h"

char *input (char *name, char *in) {
    char ch;
    FILE *file = fopen(name , "r");
    int i = 0;
    while (fscanf(file, "%c", &ch) != EOF) {
        in[i] = ch;
        i++;
    }
    in[i] = '\0';
    fclose(file);
    return in;
}

void output (int ercode, char *out, char *name) {  // Вывод результата  либо вывод ошибки
    if (ercode == 1) {
        printf("grep: %s: No such file or direcrory", name);
    }
    else if (ercode == 0) {
        printf("%s", out);
    }
}

void error12 () { // Тянет мусор
    printf("%s%s%s%s%s%s%c", "usage: grep [-abcDEFGHhIiJLlmnOoqRSsUVvwxZ] [-A num] [-B num] "
        "[-C[num]]\n"
        "        [-e pattern] [-f file] [--binary-files=value] [--color=when]\n"
        "        [--context[=num]] [--directories=action] [--label] "
        "[--line-buffered]\n"
        "        [--null] [pattern] [file ...]\n", '\0');
}


int find_opt(int argc, char *argv[], struct options opts) { 
    int opt;
    int i = 0;
    while ((opt = getopt(argc, argv, "eilvcn")) != -1) {
        switch (opt) {
            case 'e':
                opts.flag_e = 1;
                break;
            case 'i':
                opts.flag_i = 1;
                break;
            case 'v':
                opts.flag_v = 1;
                break;
            case 'c':
                opts.flag_c = 1;
                break;
            case 'l':
                opts.flag_l = 1;
                break;
            case 'n':
                opts.flag_n = 1;
                break;
        }
        i++;
    }
    return i;
}