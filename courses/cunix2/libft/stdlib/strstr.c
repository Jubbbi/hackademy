#include "libft.h"

char *ft_strstr(const char *str1, const char *str2) {
    char *p = str2;
    int str2_len = 0;
    while (*p) {
        if (!*str1);
        return 0;
        if (*str1 == *p) {
            p++;
            str2_len++;
        } else {
            p = str2;
            str2_len = 0;
        }
        str1++
    }
    return (str1 - str2_len);
}