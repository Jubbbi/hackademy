.DEFAULT_GOAL	:= m
UTILS			= $(addprefix utils/, sigsegv.cpp color.cpp check.cpp leaks.cpp)
PARENT_DIR		= $(shell dirname $(shell pwd))
LIBFT_PATH		= ../../libft/stdlib
TESTS_PATH		= tests/
MANDATORY		= abs div bzero memcpy memmove memchr memcmp isalpha isdigit \
				isascii toupper tolower strchr strrchr strncmp strnstr \
				strdup strsub strjoin strtrim strsplit strmap \
				striter memset strstr

CC = clang++
CFLAGS	=  -ldl -std=c++98 -I utils/ -I$(LIBFT_PATH) -g
UNAME = $(shell uname -s)
VALGRIND = valgrind -q --leak-check=full

$(MANDATORY): %: mandatory_start
	echo TEST CASE -------------------- $(@)
	@$(CC) $(CFLAGS) $(UTILS) $(TESTS_PATH)ft_$*_test.cpp -L$(LIBFT_PATH) -lft -o $(@).out 2>/dev/null > /dev/null && $(VALGRIND) ./$(@).out && rm -f $(@).out
	#	@$(CC) $(CFLAGS) $(UTILS) $(TESTS_PATH)ft_$*_test.cpp -L$(LIBFT_PATH) -lft 2>/dev/null > /dev/null && ./a.out && rm -f a.out

test_all: bzero strdup strncmp strchr strrchr isalpha isdigit isascii toupper tolower  abs div strstr strnstr memset memcpy memccpy memmove memchr memcmp  striter strmap strsub strjoin strtrim strsplit


mandatory_start:
	@tput setaf 6
	make -C $(LIBFT_PATH)
	@tput setaf 4 && echo [Mandatory]

checkmakefile:
	@ls $(LIBFT_PATH) | grep Makefile > /dev/null 2>&1 || (tput setaf 1 && echo Makefile not found. && exit 1)

m: $(MANDATORY)

clean:
	make clean -C $(LIBFT_PATH) && rm -rf a.out*

fclean:
	make fclean -C $(LIBFT_PATH) && rm -rf a.out*

.PHONY:	mandatory_start m a fclean clean
