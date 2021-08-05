unsigned int my_strlen(char *str) {
    unsigned int len = 0;
    char *s_p = str;
    if (str == 0) {
        return 0;
    }
    while (*s_p != 0) {
        s_p += 1; 
        len += 1;
    }
    return len;
}
