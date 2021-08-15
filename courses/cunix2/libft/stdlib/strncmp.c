#include <libft.h>


int ft_strcmp(char *str1, char *str2, size_t n) {
    unsigned int i = 0;
    while (str1[i] && str2[i] && i < n) {
        if (str1[i] > str2[i]) {
            return 1;
        } else if (str1[i] < str2[i]) {
            return -1;
        }
        str1++;
        str2++;
        i++;
    }
    if (str1[i] && !str2[i] && i < n) {
        return 1;
    } else if (!str1[i] && str2[i]) {
        return -1;
    }
    return 0;
}
