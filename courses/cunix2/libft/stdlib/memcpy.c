#include "libft.h"


void *ft_memcpy(void *dest, const void *src, unsigned int cnt) {
    char *pszDest = (char *) dest;
    const char *pszSource = (const char *) src;
    if ((pszDest != NULL) && (pszSource != NULL)) {
        while (cnt) {*(pszDest++) = *(pszSource++);
            --cnt;
        }
    }
    return dest;
}