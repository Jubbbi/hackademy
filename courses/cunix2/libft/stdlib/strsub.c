#include "libft.h"
#include <memory.h>
#include <malloc.h>

char *ft_strsub(char const *s, unsigned int start, size_t len) {
    if (s == NULL) {
        return NULL;
    }
    char *new_s = calloc(len, sizeof(char));
    if (new_s == NULL) {
        return NULL;
    }
    memcpy(new_s, s + start, len);
    return new_s;
}