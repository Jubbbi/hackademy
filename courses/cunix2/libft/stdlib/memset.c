void *ft_memset(void *buf, int ch, size_t count) {
    int i;
    unsigned char *p = buf;
    i = 0;
    while (count > 0) {
        *p = ch;
        p++;
        count--;
    }
    return (buf);
}