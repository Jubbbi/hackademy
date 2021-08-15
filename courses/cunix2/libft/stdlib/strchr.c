#include <libft.h>


char *ft_strchr(const char *str, int ch) {
    while (*str != (char) ch) {
        if (!*str) {
            return 0;
        }
        str++;
    }
    return (char *) str;
}