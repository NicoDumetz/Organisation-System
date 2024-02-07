##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile compile my hunter
##

SRC	=	organized.c \
		fonc_org.c \
		fonc_base.c \
		sort_in_sort.c


OBJ	=	$(SRC:.c=.o)

CFLAGS += -g

NAME 	= 	organized

all:	$(NAME)

$(NAME):	$(OBJ)
	cd my_printf/ && make
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -L./shell/ -lshell -L./my_printf/ -lmy

clean:
	cd my_printf/ && make clean
	rm *.o

fclean:		clean
	cd my_printf/ && make fclean
	rm -f $(NAME)

re:	fclean all
