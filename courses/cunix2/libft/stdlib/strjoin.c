#include "libft.h"
#include <string.h>
#include <inttypes.h>
#include <memory.h>
#include <malloc.h>

char *ft_strjoin(char const *s1, char const *s2) {
    char *new_s = NULL;
    size_t len1 = strlen(s1), len2 = strlen(s2);

    new_s = calloc(len1 + len2 + 1, sizeof(char));
    memcpy(new_s, s1, len1);
    memcpy(new_s + len1, s2, len2);
    return new_s;
}