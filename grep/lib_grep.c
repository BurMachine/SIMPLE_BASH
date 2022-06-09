#include <stdio.h>
#include <unistd.h>
#include "lib_grep.h"
#include <string.h>

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
    printf("%s", out);

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

char *options(int argc, char *argv[], char *form, char *PATTERN, char **PAT) { // Тянет мусор
    int opt;
    int i = 0;
    int j = 0;
    PAT[j] = PATTERN;
    while ((opt = getopt(argc, argv, "e:ilvcn")) != -1) {
        switch (opt) {
            case 'e':
                form[i] = (char)opt;
                j++;
                PAT[j] = optarg;
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
char *N_find (char *in, char *out, char *PATTERN) {
    int i = 0;
    int counter = 0;
    char tmp[500];
    int tmp_i = 0;
    int read = 1;
    int counter1 = 0;
    while (read) {
        if(i == 0 || in[i - 1] == '\n') {
            counter1++;
            tmp_i = 0;
            sprintf(tmp, "%d:", counter1);
            tmp_i = strlen(tmp);
            while(in[i] != '\n' && in[i] != '\0') {
                tmp[tmp_i] = in[i];
                i++, tmp_i++;
            }
            if(in[i] == '\0') {
                read = 0;
            }
            tmp[tmp_i] = in[i];
            i++, tmp_i++;
            tmp[tmp_i] = '\0';
        }
        if (strstr(tmp, PATTERN) != NULL) {
            strcat(out, tmp);
            counter++;
        }
    }
}