#include "libft.h"


char *ft_strnstr(char *big, char *little, size_t len) {
    if (len == 0) {
        return big;
    }
    while (big = strchr(big, little[0])) {
        if (!strncmp(big, little, len)) {
            return big;
        }
        big++;
    }
    return 0;
}