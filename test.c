#include<stdio.h>
#include<unistd.h>
#include<string.h>

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
        int n = 0;
        int l = 0;
        if(format[j] == 'E') {
            for(; in[n] != '\0';n++, l++) {
                if(in[n] == '\n') {
                    out[l] = '$';
                    l++;
                    out[l] = '\n';
                    continue;
                }
                out[l] = in[n];
            }
        }
        out[l] = '\0';
    }
    printf("%s\n", out);
}