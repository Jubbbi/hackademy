OBJ:=build/obj/bzero.o build/obj/ft_strdup.o build/obj/ft_strncmp.o build/obj/ft_strchr.o build/obj/ft_strrchr.o build/obj/ft_isalpha.o build/obj/ft_isdigit.o build/obj/ft_isascii.o build/obj/ft_toupper.o build/obj/ft_tolower.o
CFLAGS:=-I .
CC:=gcc

all: build_dir obj_comp build_lib
	echo done

build_dir:
	mkdir -p build/obj
	mkdir -p build/lib
	echo BUILD DIR READY
 
obj_comp: $(OBJ)
	echo OBJ COMPILED

build/obj/%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
	echo "I compile ${<} and output to build/obj/${@}"

build_lib:
	echo Start build lib
	ar rcs build/lib/libft.a $(OBJ) 
	echo Finish build lib

.PHONY: clean
clean:
	rm -rf build

