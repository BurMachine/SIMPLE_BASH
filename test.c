#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
//#include "cat_lib.h"
#include <stdbool.h>

struct flags {
    bool b;
    bool e;
    bool n;
    bool s;
    bool t;
    
};

char *format_N (char *out, char *in);
char *expr(int counter, char *tmp);
bool find (char *form, bool flag, char flag_name);
int string_count (char *in);
char *format_B (char *out, char *in);


int main(int argc, char *argv[]) {
    struct flags opt;
    char ch;
    FILE *file = fopen("1.txt" , "r");
    char in[500];
    int i = 0;

    while (fscanf(file, "%c", &ch) != EOF) {
        in[i] = ch;
        i++;
    }
    in[i] = '\0';
//    printf("\n!!!1");
    fclose(file);
    char format[10] = "b";
    int count = strlen(format);
    char out[500];
    for (int j = 0; j < count; j++) {
        if(find(format, opt.n, 'n') == 1) {
            format_N(out, in);
        }
        else if (find(format, opt.b, 'b') == 1) {
            format_B(out, in);
        }
    }
    printf("%s", out);
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

int string_count (char *in) {
    int count = 1;
    int i = 0;
    while (in[i] != '\0') {
        if (in[i] == '\n') {
            count++;
        }
        i++;
    }
    return count;
}

bool find (char *form, bool flag, char flag_name) {
    int i = 0;
    while (form[i] != '\0') {
        if (form[i] == flag_name) {
            flag = true;
            break;
        }
        i++;
    }
    return flag;
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
    return out;
}