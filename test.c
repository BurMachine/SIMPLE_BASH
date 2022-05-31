#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

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
    fclose(file);
    char format[10] = "beEsnt";
    int count = strlen(format);
    char out[500];
    int n = 0;
    int l = 0;
    int u = 0;
    int str_count = string_count(in);
    for (int j = 0; j < count; j++) {
        n = 0;
        l = 0;
        if(format[j] == 'n') {
            char tmp[8];
            int counter = 1;
            for (int y = 0; y < str_count; y++, counter++, l++, n++) {
                expr(counter, tmp);
                strcat(out, tmp); // Реализовать построчную фигню (strcat)
                l += 7;
                for(; in[n] != '\n'; n++, l++) {
                    out[l] = in[n];
                }
                out[l] = in[n];
            }
        }
    }
    printf("%s\n", out);
    
}


char *expr(int counter, char *tmp) {
    if (counter < 10 && counter > 0) {
        sprintf(tmp, "     %d ", counter);
        tmp[8] = '\0';    
    } else if (counter >= 10 && counter < 100) {
        sprintf(tmp, "    %d ", counter);
        tmp[8] = '\0';    
    } else if (counter >= 100 && counter < 1000) {
        sprintf(tmp, "   %d ", counter);
        tmp[8] = '\0';    
    } else if (counter >= 1000 && counter < 10000) {
        sprintf(tmp, "  %d ", counter);
        tmp[8] = '\0';    
    } else if (counter >= 10000 && counter < 100000) {
        sprintf(tmp, " %d ", counter);
        tmp[8] = '\0';    
    } else if (counter >= 100000 && counter < 1000000) {
        sprintf(tmp, "%d ", counter);
        tmp[8] = '\0';
    } 
    // else {
    //     printf("Слишком много\n");
    // }
    printf("%s\n", tmp);
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
