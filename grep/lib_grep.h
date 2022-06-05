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
int find_opt(int argc, char *argv[], struct options opts);
void error12 ();


#endif  // LIB_GREP_H