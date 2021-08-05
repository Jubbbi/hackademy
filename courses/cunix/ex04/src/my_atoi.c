#include <stdlib.h>
#include <ctype.h>
#include <math.h>

    #define ASCII_NUM_BASE      (48)

int char_to_num(char c) {
    return c - ASCII_NUM_BASE;
}

int non_negative_pow(int num, int pow) {
    int res = 1;
    for (int i = 0; i < pow; ++i) {
        res *= num;
    }
    return res;
}

int my_atoi(const char *nptr) {
    int res = 0;
    int mul = 1;
    int num_len = 0;
    const char *tmp_p = NULL;

    if (nptr == NULL) {
        return 0;
    }
    // strip front whitespaces
    while (isspace(*nptr)) {
        nptr++;
    }
    // parse sign
    if (*nptr == '-') {
        mul = -1;
        nptr++;
    }
    // count length
    tmp_p = nptr;
    while (isdigit(*tmp_p)) {
        num_len++;
        tmp_p++;
    }
    for (int i = 0; i < num_len; ++i) {
        res += non_negative_pow(10, (num_len - 1 - i)) * char_to_num(nptr[i]);
    }
    return mul * res;
}

