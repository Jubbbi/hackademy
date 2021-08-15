#include <libft.h>


int ft_isascii(int ch) {
    return ((ch <= 127) && (ch >= 0));
}
