#include<string.h>
#include<stdio.h>

char *input(char *name, char *in);
void output(char *out, int flag);

int main(int argc, char *argv[]) {
    char in[255];
    int flag = 0;
    if (argc == 1) {  // Проверка на наличие аргумента(иначе sega)
        flag = 1;
    }
    input(argv[1], in);
    output(in, flag);
}

char *input(char *name, char *in) {
    char ch;
    FILE *file = fopen(name , "r");
    if (file == NULL)
        printf("!");
    int i = 0;
    
    while (fscanf(file, "%c", &ch) != EOF) {
        in[i] = ch;
        i++;
    }
    fclose(file);
    return in;
}

void output(char *out, int flag) {
    if (flag == 1) {
        printf("Вы не ввели аргумент командной строки!");
    } else {
        printf("%s", out);
    }
}
