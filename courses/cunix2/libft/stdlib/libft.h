#ifndef _LIBFT_HEADER
#define _LIBFT_HEADER
#include <stddef.h>
#include <stdlib.h>

void ft_bzero(void *s, size_t n );
char *ft_strdup(const char *str1);
int ft_strcmp(char *str1, char *str2, size_t n);
char *ft_strchr(const char *str, int ch);
char *ft_strrchr(const char *str, int sym);
int ft_isalpha(int ch);
int ft_isdigit(int ch);
int ft_isascii(int ch);
int ft_toupper(int ch);
int ft_tolower(int ch);

int ft_abs(int num);
div_t ft_div(int numer, int denom);
char *ft_strstr(const char *str1, const char *str2);
char *ft_strnstr(char *big, char *little, size_t len);
void *ft_memset(void *buf, int ch, size_t count);
void *ft_memcpy(void *dest, const void *src, unsigned int cnt);
void *ft_memccpy(void *dest, const void *src, int ch, size_t cnt);
void *ft_memmove(void *dest, const void *src, unsigned int n);
void *ft_memchr(register const PTR src_void, int c, size_t length);
int ft_memcmp(const void *s1, const void *s2, size_t n);

void ft_striter(char* s, void (*f)(char*));
char* ft_strmap(char const *s, char (*f)(char));
char* ft_strsub(char const *s, unsigned int start, size_t len);
char* ft_strjoin(char const *s1, char const *s2);
char* ft_strtrim(char const *s);
char** ft_strsplit(char const *s, char c);

#endif
