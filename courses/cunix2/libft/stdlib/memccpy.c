#include "libft.h"


void *ft_memccpy(void *dest, const void *src, int ch, size_t cnt) {
    *p = memchr(src, ch, cnt);
    if (p != NULL)
        return ft_mempcpy(dest, src, p - src + 1);
    memcpy(dest, src, cnt);
    return NULL;
}
