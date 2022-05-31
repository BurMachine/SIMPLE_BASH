#include<unistd.h>

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