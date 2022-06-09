#include "s21_cat.h"

int main(int argc, char *argv[]) {
    int err = 1;
    opts flag = {
        .b = 0,
        .e = 0,
        .n = 0,
        .s = 0,
        .t = 0,
        .v = 0,
    };
    err = flags(argc, argv, &flag);
    if (flag.b == 1) {
        flag.n = 0;
    }
    while (optind < argc) {
        err = read_file(argv, &flag);
        optind++;
    }
    return err;
}

int flags(int argc, char *argv[], opts *flag) {
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

int read_file(char *argv[], opts *flag) {
    FILE *file;
    int ret = 0;

    file = fopen(argv[optind], "r");

    if (file != NULL) {
        int str_count = 1;
        int empty_str_count = 0;
        int last_sym = '\n';

        while (1) {
            int cur_c = fgetc(file);
            if (cur_c == EOF) {
                break;
            }
            if (flag->s && cur_c == '\n' && last_sym == '\n') {
                empty_str_count++;
                if (empty_str_count > 1) {
                    continue;
                }
            } else {
                empty_str_count = 0;
            }
            if (last_sym == '\n' && ((flag->b && cur_c != '\n') || flag->n)) {
                printf("%6d\t", str_count++);
            }
            if (flag->t && cur_c == '\t') {
                printf("^");
                cur_c = 'I';
            }
            if (flag->e && cur_c == '\n') {
                    printf("$");
            }
            if (flag->v) {
                if ((cur_c >= 0 && cur_c < 9) || (cur_c > 10 && cur_c < 32)
                || (cur_c > 126 && cur_c <= 160)) {
                printf("^");
                if (cur_c > 126) {
                    cur_c -= 64;
                } else {
                cur_c += 64;
                }
                }
            }
            printf("%c", cur_c);
            last_sym = cur_c;
        }
        fclose(file);
    } else {
        ret = -1;
    }
    return ret;
}
