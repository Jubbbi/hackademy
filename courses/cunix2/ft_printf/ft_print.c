#include <unistd.h>
#include <string.h>
#include <malloc.h>
#include <errno.h>
#include <stdio.h>

int ft_print(const char *s) {
    int status = 0;
    ssize_t s_len = strlen(s);
    ssize_t written_bytes = 0,
            written_now;
    char *tmp_buf = malloc(s_len + 1);
    if (tmp_buf == NULL) {
        return -1;
    }
    memcpy(tmp_buf, s, s_len);
    tmp_buf[s_len] = '\n';
    s_len += 1;

    while (written_bytes < s_len) {
        written_now = write(STDOUT_FILENO, tmp_buf + written_bytes, s_len - written_bytes);
        if (written_now == -1) {
            if (errno == EINTR)
                continue;
            else {
                //                *status = errno;
                ferror(stdout);
                status = EOF;
                goto out;
            }
        } else {
            written_bytes += written_now;
        }
    }
    status = 0;

    out:
    free(tmp_buf);
    return status;
}

int ft_printc(char c) {
    char s[2] = {c, '0'};
    return ft_print(s);
}
