#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include "cat_lib.h"

char *expr(int counter, char *tmp);
int string_count (char *in);
int main(int argc, char *argv[]) {
    char ch;
    FILE *file = fopen("1.txt" , "r");
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
    int n = 0;
    int l = 0;
    for (int j = 0; j < count; j++) {
        n = 0;
        l = 0;
        if(format[j] == 'n') {
<<<<<<< HEAD
            
        }
    }
    printf("%s\n", out);
=======
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
    }
    printf("%s", out);
>>>>>>> d6a4e2f8c13763109857b4aa578f39256349e2f7
}


char *expr(int counter, char *tmp) {
    if (counter < 10 && counter > 0) {
        sprintf(tmp, "     %d ", counter);
    } else if (counter >= 10 && counter < 100) {
        sprintf(tmp, "    %d ", counter);
    } else if (counter >= 100 && counter < 1000) {
        sprintf(tmp, "   %d ", counter);  
    } else if (counter >= 1000 && counter < 10000) {
        sprintf(tmp, "  %d ", counter);  
    } else if (counter >= 10000 && counter < 100000) {
        sprintf(tmp, " %d ", counter);  
    } else if (counter >= 100000 && counter < 1000000) {
        sprintf(tmp, "%d ", counter);
    } 
    // else {
    //     printf("Слишком много\n");
    // }
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
