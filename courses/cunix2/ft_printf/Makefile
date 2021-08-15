OBJ:=build/obj/ft_printf.o build/obj/ft_print.o
CFLAGS:=-I .
CC:=gcc

all: build_dir obj_comp build_lib
	echo done

build_dir:
	mkdir -p build/obj
	echo BUILD DIR READY

obj_comp: $(OBJ)
	echo OBJ COMPILED

build/obj/%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
	echo "I compile ${<} and output to build/obj/${@}"

build_lib:
	echo Start build lib
	ar rcs libftprintf.a $(OBJ)
	echo Finish build lib

.PHONY: clean
clean:
	rm -rf build
	rm -rf libft_printf.a

