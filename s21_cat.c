#include "s21_cat.h"

int main(int argc, char *argv[]) {
    int err = 1;
    opts flag = {
        flag.b = 0,
        flag.e = 0,
        flag.n = 0,
        flag.s = 0,
        flag.t = 0,
        flag.v = 0,
    };
    err = pars(argc, argv, &flag);
    if (flag.b == 1) {
        flag.n = 0;
    }
    while (optind < argc) {
        err = read_file(argv, &flag);
        optind++;
    }
    return err;
}

int pars
(int argc, char *argv[], opts *flag) {
    int f;
    int ret = 0;
    int index = 0;
    static struct option options[] = {
        {"number-nonblank", 0, 0, 'b'},
        {"number", 0, 0, 'n'},
        {"squeeze-blank", 0, 0, 's'},
        {0, 0, 0, 0},
    };
    while ((f = getopt_long(argc, argv, "bEnsTvet", options, &index)) != -1) {
        if (f == 'b') {
        flag->b = 1;
        }
        if (f == 'E') {
        flag->e = 1;
        }
        if (f == 'n') {
        flag->n = 1;
        }
        if (f == 's') {
        flag->s = 1;
        }
        if (f == 'T') {
        flag->t = 1;
        }
        if (f == 'v') {
        flag->v = 1;
        }
        if (f == 'e') {
        flag->e = 1;
        flag->v = 1;
        }
        if (f == 't') {
        flag->t = 1;
        flag->v = 1;
        }
    }
    return ret;
}

int file_processing(char *argv[], opts *flag) {
    FILE *file;
    int ret = 0;

    file = fopen(argv[optind], "r");

    if (file != NULL) {
        int str_count = 1;
        int empty_str_count = 0;
        int last_sym = '\n';

        while (1) {
            int out = fgetc(file);
            if (out == EOF) {
                break;
            }
            if (flag->s && out == '\n' && last_sym == '\n') {
                empty_str_count++;
                if (empty_str_count > 1) {
                    continue;
                }
            } else {
                empty_str_count = 0;
            }
            if (last_sym == '\n' && ((flag->b && out != '\n') || flag->n)) {
                printf("%6d\t", str_count++);
            }
            if (flag->t && out == '\t') {
                printf("^");
                out = 'I';
            }
            if (flag->e && out == '\n') {
                    printf("$");
            }
            if (flag->v) {
                if ((out >= 0 && out < 9) || (out > 10 && out < 32)
                || (out > 126 && out <= 160)) {
                printf("^");
                if (out > 126) {
                    out -= 64;
                } else {
                out += 64;
                }
                }
            }
            printf("%c", out);
            last_sym = out;
        }
        fclose(file);
    } else {
        ret = -1;
    }
    return ret;
}
