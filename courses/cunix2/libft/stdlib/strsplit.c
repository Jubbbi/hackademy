#include "libft.h"
#include <malloc.h>
#include <memory.h>
#include <inttypes.h>

char **ft_strsplit(char const *s, char c) {
    const char *begin = s, *end;
    char **res_arr = NULL;
    char *new_elem = NULL;
    size_t arr_len = 0, index = 0;

    if (s == NULL) {
        return NULL;
    }
    if (*s == 0) {
        return NULL;
    }

    while (*begin) {
        while (*begin && *begin != c) {
            begin++;
        }
        end = begin;
        while (*end && *end == c) {
            end++;
        }
        if (begin != end) {
            arr_len++;
        }
    }

    res_arr = calloc(arr_len, sizeof(char *));

    begin = s;
    while (*begin) {
        while (*begin && *begin != c) {
            begin++;
        }
        end = begin;
        while (*end && *end == c) {
            end++;
        }
        if (begin != end) {
            new_elem = calloc(end - begin + 1, sizeof(char));
            if (new_elem == NULL) {
                for (int i = 0; i < index + 1; ++i) {
                    free(res_arr[i]);
                }
                return NULL;
            }
            memcpy(new_elem, begin, end - begin);
            res_arr[index] = new_elem;
            index++;
        }
    }

    return res_arr;
}