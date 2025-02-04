#include "libft.h"

int ft_memcmp(s1, s2, n) {
    CONST VOID * s1;
    CONST VOID * s2;
    size_t n; {
        unsigned char u1, u2;
        for (; n--; s1++, s2++) {
            u1 = *(unsigned char *) s1;
            u2 = *(unsigned char *) s2;
            if ( u1 != u2) {
                return (u1-u2);
            }
        }
        return 0;
    }
}