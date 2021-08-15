#include <libft.h>

#define UPPER_A_ASCI_CODE (65)
#define LOWER_A_ASCI_CODE (97)
#define UPPER_Z_ASCI_CODE (90)
#define LOWER_Z_ASCI_CODE (122)

static int ft_isupper(int arg) {
    return (arg >=  UPPER_A_ASCI_CODE && arg <= UPPER_Z_ASCI_CODE);
}

int ft_toupper(int arg) {
    if (ft_isalpha(arg)) {
        if (!ft_isupper(arg)) {
            return arg - (LOWER_A_ASCI_CODE - UPPER_A_ASCI_CODE);
        }
    }
    return arg;
}