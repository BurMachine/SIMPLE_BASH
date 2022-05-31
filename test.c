#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

void expr(int counter, char *tmp);
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
    for (int j = 0; j < count; j++) {
        n = 0;
        l = 0;
        if(format[j] == 'n') {
            int counter = 1;
            int n = 0;
            int l = 7;
            char *tmp_2 = malloc(8*sizeof(char));
            for (; in[n] != '\0'; n++, l++) {
                expr(counter, tmp_2);
                strcat(out, tmp_2);
                l += 7;
                if (in[n] == '\n') {
                    out[l] = in[n];
                    counter++;
                    continue;
                }
                out[l] = in[n];
            }
            out[l] = '\0';
            free(tmp_2);
        }
    }
    printf("%s\n", out);
    
}

void expr(int counter, char *tmp) {
    if (counter < 10 && counter > 0) {
        sprintf(tmp, "     %d ", counter);
        tmp[8] = '\0';    
    } else if (counter >= 10 && counter > 100) {
        sprintf(tmp, "    %d ", counter);
        tmp[8] = '\0';    
    } else if (counter >= 100 && counter > 1000) {
        sprintf(tmp, "   %d ", counter);
        tmp[8] = '\0';    
    } else if (counter >= 1000 && counter > 10000) {
        sprintf(tmp, "  %d ", counter);
        tmp[8] = '\0';    
    } else if (counter >= 10000 && counter > 100000) {
        sprintf(tmp, " %d ", counter);
        tmp[8] = '\0';    
    } else if (counter >= 100000 && counter > 1000000) {
        sprintf(tmp, "%d ", counter);
        tmp[8] = '\0';
    } 
    // else {
    //     printf("Слишком много\n");
    // }
}
