#include "libft.h"

char *ft_strmap(char const *s, char (*f)(char)) {
    int len = 0;
    const char *s_p = NULL;
    char *new_s = NULL;
    if (s == NULL) {
        return NULL;
    }
    s_p = s;
    while (*s_p) {
        len++;
        s_p++;
    }
    new_s = calloc(len + 1, sizeof(char));
    if (new_s == NULL) {
        return NULL;
    }
    for (int i = 0; i < len; ++i) {
        new_s[i] = f(s[i]);
    }
    return new_s;
}