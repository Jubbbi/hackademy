#include "libft.h"

void *ft_memmove(void *dest, const void *src, unsigned int n) {
    char *pDest = (char *) dest;
    const char *pSrc = (const char *) src;
    char *tmp = (char *) malloc(sizeof(char) * n);
    if (NULL == tmp) {
        return NULL;
    } else {
        unsigned int i = 0;
        for (i = 0; i < n; ++i) {
            *(tmp + i) = *(pSrc + i);
        }
        for (i = 0; i < n; ++i) {
            *(pDest + i) = *(tmp + i);
        }
        free(tmp);
    }
    return dest;
}
