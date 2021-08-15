OBJ:=build/obj/bzero.o build/obj/strdup.o build/obj/strncmp.o build/obj/strchr.o build/obj/strrchr.o build/obj/isalpha.o build/obj/isdigit.o build/obj/isascii.o build/obj/toupper.o build/obj/tolower.o
CFLAGS:=-I . -Wall
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
	ar rcs libft.a $(OBJ)
	echo Finish build lib

.PHONY: clean
clean:
	rm -rf build
	rm -f libft.a

