#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "lib_grep.h"


int find(char *in, char *out, char *PATTERN, char flag);
char *processing(char *in, char *form, char *out, char *PATTERN);


int main(int argc, char *argv[]) {
    char format[15];
    char input_arr[500];
    char out[500];
    char *pat[500];
    int er_code = 0;
    if (argc > 2) {
    input(argv[argc - 1], input_arr);
    options(argc, argv, format, PATTERN, pat);
    processing(input_arr, format, out, argv[argc - 2]);
    output(er_code, out, argv[argc - 1]);
    } else {
        error12();
        return 1;
    }
}

char *processing(char *in, char *form, char *out, char *PATTERN) {
    char tmp[500];
    int flag_v = 0;
    for (int i = 0; form[i] != '\0'; i++) {
        if (form[i] == 'c') {
            sprintf(tmp, "%d\0", find(in, out, PATTERN, -1));
            copy(tmp, out);
        } else if (form[i] == 'v') {
            find(in, tmp, PATTERN, 'v');
            copy(tmp, out);
        } else if (form[i] == 'n') {
            find(in, tmp, PATTERN, 'n');
            copy(tmp, out);
        } else if (form[i])
    }
    if(form[0] == '\0') {
        find(in, out, PATTERN, -1);
    }
}

int find(char *in, char *out, char *PATTERN, char flag) {
    int i = 0;
    int counter = 0;
    char tmp[500];
    int tmp_i = 0;
    int read = 1;
    if (flag == -1) {
        while (read) {
            if(i == 0 || in[i - 1] == '\n') {
                tmp_i = 0;
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
    } else if (flag == 'v') {
        while (read) {
            if(i == 0 || in[i - 1] == '\n') {
                tmp_i = 0;
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
            if (strstr(tmp, PATTERN) == NULL) {
                strcat(out, tmp);
                counter++;
            }
        }
    } else if (flag == 'i') {
        while (read) {
            if(i == 0 || in[i - 1] == '\n') {
                tmp_i = 0;
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
            if (strcasestr(tmp, PATTERN) != NULL) {
                strcat(out, tmp);
                counter++;
            }
        }
    } else if (flag == 'n') {
        N_find(in, out, PATTERN);
    }
    return counter;
}
