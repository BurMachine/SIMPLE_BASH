#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>


char *format_N (char *out, char *in);
char *expr(int counter, char *tmp);
int string_count (char *in);
char *format_T(char *out, char *in);
int main(int argc, char *argv[]) {
    char ch;
    FILE *file = fopen("3.txt" , "r");
    char in[500];
    int i = 0;

    while (fscanf(file, "%c", &ch) != EOF) {
        in[i] = ch;
        i++;
    }
    in[i] = '\0';
//    printf("in:\n%s\n", in);
//    printf("\n%c", in[i]);
    fclose(file);
    char format[10] = "beEsnt";
    int count = strlen(format);
    char out[500];
    for (int j = 0; j < count; j++) {
        if (format[j] == 's') {
            format_T(out, in);
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

char *format_S (char *out, char *in) {
    int k = 0;
    int l = 0;
    while (in[k] != '\0') {
        if (in[k] != '\n') {
            out[l] = in[k];
            ++k, l++;
        }
        if (in[k] == '\n' && in[k - 1] == '\n') {
            out[l] = in[k];
            l++, k++;
            while (in[k] == '\n') {
                k++;
            }
        }
        if (in[k] == '\n' && in[k - 1] != '\n') {
            out[l] = in[k];
            l++, k++;
        }
    }
    return out;
}
char *format_T(char *out, char *in) {
    int l = 0, k = 0;
    while (in[k] != '\0') {
        if (in[k] == '\t') {
            out[l] = '^';
            l++;
            out[l] = 'I';
            l++, k++;
        } else {
            out[l] = in[k];
            l++, k++;
        }
    }
    out[l] = '\0';
    return out;
}

