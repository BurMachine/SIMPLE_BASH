#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include "cat_lib.h"

char *input(char *name, char *in);
void output(char *out, int flag);
char *options(int argc, char *argv[], char *form);
char *processing(char *format, char *input, char *out);

int main(int argc, char *argv[]) {
    char in[255];
    char out[255];
    char format[10];
    int flag = 0;
    if (argc == 1) {  // Проверка на наличие аргумента(иначе sega)
        flag = 1;
    }
    input(argv[argc - 1], in);
    options(argc, argv, format);
    processing(format, in, out);
    output(out, flag);
}

char *processing(char *format, char *input, char *out) {
    int count = strlen(format);
    int n = 0;
    int l = 0;
    char tmp[500];
    copy(input, out);
    for (int j = 0; j < count; j++) {
        n = 0; l = 0;
        if(format[j] == 'e') {
            for(; out[n] != '\0';n++, l++) {
                if(out[n] == '\n') {
                    tmp[l] = '$';
                    l++;
                    tmp[l] = '\n';
                    continue;
                }
                tmp[l] = out[n];
            }
            tmp[l] = '\0';
            copy(tmp, out);
            continue;
        } 
        if (format[j] == 'n') {
            format_N(tmp, out);
            copy(tmp, out);
        }
    }
    return out;
}

char *input(char *name, char *in) {
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

void output(char *out, int flag) {
    if (flag == 1) {
        printf("Вы не ввели аргумент командной строки!");
    } else {
        printf("%s", out);
    }
}
