#include <unistd.h>
#include <stdio.h>

char *options(int argc, char *argv[], char *form) {
    int opt;
    int i = 0;
    while ((opt = getopt(argc, argv, "benstE")) != -1) {
        switch (opt) {
            case 'b':
                form[i] = (char)opt;
                break;
            case 'e':
                form[i] = (char)opt;
                break;
            case 'n':
                form[i] = (char)opt;
                break;
            case 's':
                form[i] = (char)opt;
                break;
            case 't':
                form[i] = (char)opt;
                break;
            case 'E':
                form[i] = (char)opt;
                break;
        }
        i++;
    }
    return form;
}

void copy (char *in, char *out) {
    int i = 0;
    while (in[i] != '\0') {
        out[i] = in[i];
        ++i;
    }
    out[i] = '\0';
}

char *expr(int counter, char *tmp) {
    if (counter < 10 && counter > 0) {
        sprintf(tmp, "     %d\t", counter);
        tmp[8] = '\0';
    } else if (counter >= 10 && counter < 100) {
        sprintf(tmp, "    %d\t", counter);
        tmp[8] = '\0';
    } else if (counter >= 100 && counter < 1000) {
        sprintf(tmp, "   %d\t", counter);
        tmp[8] = '\0';
    } else if (counter >= 1000 && counter < 10000) {
        sprintf(tmp, "  %d\t", counter);
        tmp[8] = '\0';
    } else if (counter >= 10000 && counter < 100000) {
        sprintf(tmp, " %d\t", counter);
        tmp[8] = '\0';
    } else if (counter >= 100000 && counter < 1000000) {
        sprintf(tmp, "%d\t", counter);
        tmp[8] = '\0';
    }
    return tmp;
}
char *format_N (char *out, char *in) {
    int n = 0;
    int l = 0;
    int counter = 1;
    char tmp[10];
    while (in[n] != '\0') {
        int g = 0;
        if(l == 0 ) {
            expr(counter, tmp);
            while (tmp[g] != '\0') {
                out[l] = tmp[g];
                l++;
                g++;
            }
        }
        if (in[n] == '\n') {
            g = 0;
            counter++;
            out[l] = in[n];
            l++;
            n++;
            expr(counter, tmp);
            while (tmp[g] != '\0') {
                out[l] = tmp[g];
                l++;
                g++;
            }
        }
        if (l != 0 && in[n] != '\n') {
            out[l] = in[n];
            n++, l++;
        }
    }
    out[l] = '\0';
}

char *format_B (char *out, char *in) {
    int n = 0, m = 0;
    int g = 0;
    int counter = 1;
    char tmp[10];
    while (in[n] != '\0') {
        if (n == 0 && in[n] == '\n') {
            out[m] = in[n];
            n++, m++;
        }
        if (n == 0 && in[n] != '\n') {
            g = 0;
            expr(counter, tmp);
            while (tmp[g] != '\0') {
                out[m] = tmp[g];
                m++;
                g++;
            }
            counter++;
        }
        while (in[n] != '\n' && in[n] != '\0') {
            if (in[n - 1] == '\n') {
                g = 0;
                expr(counter, tmp);
                while (tmp[g] != '\0') {
                    out[m] = tmp[g];
                    m++;
                    g++;
                }
                counter++;
            }
            out[m] = in[n];
            n++, m++;
        }
        if (in[n] == '\n' && in[n - 1] != '\n') {
            g = 0;
            out[m] = in[n];
            n++, m++;
        }
        if (in[n] == '\n' && in[n - 1] == '\n') {
            out[m] = in[n];
            m++, n++;
        }
    }
    out[m] = '\0';
    return out;
}