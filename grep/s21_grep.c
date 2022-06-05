#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "lib_grep.h"


int find(char *in, char *out, char *PATTERN);

int main(int argc, char *argv[]) {
    struct options opts;
    opts.flag_e = 0, opts.flag_i = 0, opts.flag_v = 0; 
    opts.flag_c = 0, opts.flag_n = 0, opts.flag_l = 0;
    char input_arr[500];
    char out[500];
    int er_code;
    if (argc > 2) {
    input(argv[argc - 1], input_arr);
    printf("\n%d\n", find_opt(argc, argv, opts));
    er_code = find(input_arr, out, argv[argc - 2]);
    output(er_code, out, argv[argc - 1]);

    } else {
        error12();
        return 1;
    }
}



int find(char *in, char *out, char *PATTERN) {
    int i = 0;
    char tmp[500];
    int tmp_i = 0;
    int rreturn = 0;
    int read = 1;
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
        }
    }
    if (strlen(out) != 0) {}
    else {
        rreturn = 1;
    }
    return rreturn;
}

