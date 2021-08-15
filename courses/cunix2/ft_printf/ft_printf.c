#include <stdarg.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <stdlib.h>

#define FALSE   (0)
#define TRUE    (!FALSE)


int ft_printc(char c);

int ft_print(const char *s);

typedef enum ft_printf_arg_type_e {
    FT_PRINTF_ARG_INVALID_E = 0,
    FT_PRINTF_ARG_CHAR_E,   // %c
    FT_PRINTF_ARG_INT_E,    // %i
    FT_PRINTF_ARG_DIGIT_E,  // %d
    FT_PRINTF_ARG_STRING_E // %s
} ft_printf_arg_type_e;

typedef struct ft_print_format_t {
    ft_printf_arg_type_e type;
    uint8_t left_aligned;  // is left aligned
    uint8_t zero_pad;      // use '0' as padding
    uint8_t space_sign;    // show '-' sign or ' '  for positive
    uint8_t show_sign;     // show sign explicitly
    int min_width;     // minimal param width
} ft_print_format_t;

static ft_printf_arg_type_e get_arg_type(char c) {
    switch (c) {
        case 'c':
            return FT_PRINTF_ARG_CHAR_E;
        case 'i':
            return FT_PRINTF_ARG_INT_E;
        case 'd':
            return FT_PRINTF_ARG_DIGIT_E;
        case 's':
            return FT_PRINTF_ARG_STRING_E;
        default:
            return FT_PRINTF_ARG_INVALID_E;
    }
}

typedef enum ft_arg_pars_stage {
    FT_PARSE_ARG_FLAGS,
    FT_PARSE_ARG_WIDTH,
    FT_PARSE_ARG_TYPE,
    FT_PARSE_ARG_END
} ft_arg_pars_stage;


static int ft_digit_num(int n) {
    int count = 0;
    if (n < 0) {
        n = -n;
    }
    while (n != 0) {
        n /= 10;     // n = n/10
        ++count;
    }
}

/*
 * return values:
 *      0 -- SUCCESS
 *    < 0 -- ERROR
 *    > 0 -- ARG LENGTH
 */
static int ft_print_arg(const char *format, va_list *argv_p) {
    int status = -4; // empty arg exit code
    size_t length, arg_length = 0;
    int int_arg;
    char *str_arg, *arg_buf, pad_char = ' ';
    const char *s_p, *tmp_s_p;
    ft_arg_pars_stage parse_stage = FT_PARSE_ARG_FLAGS;
    ft_print_format_t pr_format;
    memset((void *) &pr_format, 0, sizeof(pr_format));

    /************************** Parse Format **************************/
    while (*format && parse_stage != FT_PARSE_ARG_END) {
        pr_format.type = get_arg_type(*format);
        if (pr_format.type != FT_PRINTF_ARG_INVALID_E) {
            status = 0; // SUCCESS exit code
            arg_length = 1;
            parse_stage = FT_PARSE_ARG_END;
            continue;
        } else if (parse_stage == FT_PARSE_ARG_TYPE) {
            status = -3; // unsupported type
            goto out;
        }

        if (parse_stage == FT_PARSE_ARG_FLAGS) {
            if (*format != '0' && isdigit(*format)) {
                parse_stage = FT_PARSE_ARG_WIDTH;
            } else {
                switch (*format) {
                    case ' ':
                        if (!pr_format.show_sign) {
                            pr_format.space_sign = TRUE;
                        }
                        break;
                    case '+':
                        if (!pr_format.space_sign) {
                            pr_format.show_sign = TRUE;
                        }
                        break;
                    case '-':
                        pr_format.left_aligned = TRUE;
                        break;
                    case '0':
                        if (!pr_format.left_aligned) {
                            pr_format.zero_pad = TRUE;
                        }
                        break;
                    default:
                        status = -2;
                        goto out;
                }
            }
        }

        if (parse_stage == FT_PARSE_ARG_WIDTH) {
            length = 0;
            s_p = format;
            while (*s_p && isdigit(*s_p)) {
                length++;
                s_p++;
            }
            tmp_s_p = calloc(length + 1, sizeof(char));
            if (tmp_s_p == NULL) {
                status = -1;
                goto out;
            }
            memcpy((void *) tmp_s_p, format, length);
            pr_format.min_width = atoi(tmp_s_p);
            free((void *) tmp_s_p);
            parse_stage = FT_PARSE_ARG_TYPE;
            arg_length += length;
        }
        format++;
        arg_length++;
    }

    /************************** Calculate BUF size **************************/
    switch (pr_format.type) {
        case FT_PRINTF_ARG_CHAR_E:
            int_arg = va_arg(*argv_p, int);
            length = 1;
            break;

        case FT_PRINTF_ARG_INT_E:
        case FT_PRINTF_ARG_DIGIT_E:
            int_arg = va_arg(*argv_p, int);
            length = ft_digit_num(int_arg);
            if (int_arg < 0 || pr_format.show_sign || pr_format.space_sign) {
                length++;
            }
            break;
        case FT_PRINTF_ARG_STRING_E:
            str_arg = va_arg(*argv_p, char *);
            length = strlen(str_arg);
            break;
        default:
            status = -5; // unexpected type value
            goto out;
    }
    if (length < pr_format.min_width) {
        length = pr_format.min_width;
    }

    /************************** Print BUF **************************/
    arg_buf = calloc(length + 1, sizeof(char));
    if (arg_buf == NULL) {
        status = -6;
        goto out;
    }
    if (pr_format.zero_pad) {
        pad_char = '0';
    }
    tmp_s_p = arg_buf;
    // TODO 1: check what is the real_length of the arg VS the padding and BUF length
    // TODO 2: render string
    switch (pr_format.type) {
        case FT_PRINTF_ARG_CHAR_E:
            arg_buf[0] = (char) int_arg;
            break;

        case FT_PRINTF_ARG_INT_E:
        case FT_PRINTF_ARG_DIGIT_E:
            int_arg = va_arg(*argv_p, int);
            length = ft_digit_num(int_arg);
            if (int_arg < 0 || pr_format.show_sign || pr_format.space_sign) {
                length++;
            }
            break;
        case FT_PRINTF_ARG_STRING_E:
            str_arg = va_arg(*argv_p, char *);
            length = strlen(str_arg);
            break;
        default:
            status = -5; // unexpected type value
            goto out;
    }

    status = ft_print(arg_buf);

    out:
    if (status == 0) {
        return arg_length;
    }
    return status;
}

int ft_printf(const char *format, ...) {
    int status = 0;
    va_list argv;

    va_start(argv, format);
    while (format && *format) {
        if (*format == '%' && *++format != '%') {
            status = ft_print_arg(format, &argv);
            if (status != 0) {
                goto out;
            }
        }

        status = ft_printc(*format++);
        if (status != 0) {
            goto out;
        }
    }

    out:
    va_end(argv);
    return status;
}


//int main()
//{
//    ts_printf("This is text, with %%, but without data.\n\n");
//    string s1="THIS IS STRING";
//    char   cs2[]="this is c-string";
//    int x = 5;
//    double z = 1.23;
//    ts_printf("std::string printed: \"%s\",\nOld-style string: \"%s\",\n"
//              "int: %s,\ndouble: %s.\n", s1, cs2, x, z);
//    return 0;
//}


