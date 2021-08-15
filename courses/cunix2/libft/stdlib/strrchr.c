#include <libft.h>


char *ft_strrchr(const char *str, int sym) {
    const char *ch_p = str;
    if(!*str) {
        return NULL;
    }
    while (*(++ch_p)) {}
    while (*ch_p != (char) sym) {
        if (str == ch_p) {
            return 0;
        }
        ch_p--;
    }
    return (char *) ch_p;
}