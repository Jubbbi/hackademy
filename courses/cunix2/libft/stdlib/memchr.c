#include "libft.h"

void *ft_memchr(register const PTR src_void, int c, size_t length) {
    const unsigned char *src = (const unsigned char *) src_void;

    while (length-- > 0) {
        if (*src == c)
            return (PTR) src;
        src++;
    }
    return NULL;
}