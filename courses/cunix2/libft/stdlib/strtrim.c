#include "libft.h"
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

char *ft_strtrim(char const *s) {
    char *new_s = NULL;
    char *tmp_p = s + strlen(s) - 1;
    if (s == NULL) {
        return NULL;
    }
    while (isspace(*s)) {
        s++;
    }
    while (isspace(*tmp_p) && tmp_p > s) {
        tmp_p--;
    }
    if (tmp_p < s) {
        return NULL;
    }
    new_s = calloc(s - tmp_p + 2, sizeof(char));
    if (new_s == NULL) {
        return NULL;
    }
    memcpy(new_s, s, s - tmp_p + 1);
    return new_s;
}