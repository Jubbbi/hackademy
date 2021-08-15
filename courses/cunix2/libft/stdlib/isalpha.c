#include <libft.h>

#define UPPER_A_ASCI_CODE (65)
#define LOWER_A_ASCI_CODE (97)
#define UPPER_Z_ASCI_CODE (90)
#define LOWER_Z_ASCI_CODE (122)

int ft_isalpha(int ch) {
    if (LOWER_A_ASCI_CODE <= ch && ch <= LOWER_Z_ASCI_CODE) {
        return 1;
    }
    if (UPPER_A_ASCI_CODE <= ch && ch <= UPPER_Z_ASCI_CODE) {
        return 1;
    }
    return 0;
}