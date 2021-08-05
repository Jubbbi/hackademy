#include <malloc.h>

#define ASCII_NUM_BASE      (48)

char num_to_char(int num) {
    return num + ASCII_NUM_BASE;
}

int number_buf_len(int num) {
    // reserve buf for 1 digit and '\0' string ending
    int buf_len = 2;
    if (num < 0) {
        buf_len++;
        num *= -1;
    }
    while (num > 9) {
        buf_len++;
        num /= 10;
    }
    return buf_len;
}

char* my_itoa(int nmb) {
    int  str_len = number_buf_len(nmb);
    char *res_str = malloc(str_len);
    char *tmp_p = res_str + str_len - 1;

    if (nmb < 0) {
        *res_str = '-';
        nmb *= -1;
    }
    *tmp_p-- = '\0';
    do {
        *tmp_p-- = num_to_char(nmb % 10);
        nmb /= 10;
    } while (nmb > 0);
    return res_str;
}
