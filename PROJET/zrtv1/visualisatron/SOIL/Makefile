NAME = lib/libsoil.a

all: $(NAME)

$(NAME):
	mkdir -p lib
	gcc src/*.c -c
	ar rc $(NAME) *.o
	ranlib $(NAME)
