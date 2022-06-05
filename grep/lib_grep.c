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

void error12 () { 
    printf("%s%s\n%s\n%s%s\n%s\n%c", "usage: grep [-abcDEFGHhIiJLlmnOoqRSsUVvwxZ] [-A num] [-B num] ",
        "[-C[num]]",
        "        [-e pattern] [-f file] [--binary-files=value] [--color=when]",
        "        [--context[=num]] [--directories=action] [--label] ",
        "[--line-buffered]",
        "        [--null] [pattern] [file ...]", '\0');
}

void copy (char *in, char *out) {
    int i = 0;
    while (in[i] != '\0') {
        out[i] = in[i];
        ++i;
    }
    out[i] = '\0';
}

char *options(int argc, char *argv[], char *form) { // Тянет мусор
    int opt;
    int i = 0;
    while ((opt = getopt(argc, argv, "eilvcn")) != -1) {
        switch (opt) {
            case 'e':
                form[i] = (char)opt;
                break;
            case 'i':
                form[i] = (char)opt;
                break;
            case 'l':
                form[i] = (char)opt;
                break;
            case 'n':
                form[i] = (char)opt;
                break;
            case 'c':
                form[i] = (char)opt;
                break;
            case 'v':
                form[i] = (char)opt;
                break;
        }
        i++;
    }
    form[i] = '\0';
    return form;
}