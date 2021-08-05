char *my_strcpy(char *dest, const char *src) {
	char *res_p = dest;
	if (dest == 0 || src == 0) {
		return 0;
	}
	do {
		*dest = *src;
		dest++;	
	} while (*src++ != 0);
	return res_p;
}

