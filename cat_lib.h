#ifndef CAT_LIB_H
#define CAT_LIB_H


char *options(int argc, char *argv[], char *form);
void copy (char *in, char *out);
char *format_N (char *out, char *in);
char *format_B (char *out, char *in);
char *format_S (char *out, char *in);
char *format_T(char *out, char *in);
char *expr(int counter, char *tmp);

#endif  // CAT_LIB_H