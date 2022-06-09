#ifndef LIB_GREP_H
#define LIB_GREP_H

struct options {
    int flag_e;
    int flag_i;
    int flag_v;
    int flag_c;
    int flag_l;
    int flag_n;
    // int flag_h;
    // int flag_s;
    // int flag_f;
    // int flag_o;
};

char *input (char *name, char *in);
void output (int ercode, char *out, char *name);
char *options(int argc, char *argv[], char *form, char *PATTERN, char **PAT);
void copy (char *in, char *out);
void error12 ();

char *N_find (char *in, char *out, char *PATTERN);


#endif  // LIB_GREP_H