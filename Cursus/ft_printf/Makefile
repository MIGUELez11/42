SRC		=	$(shell find -f functions/*.c)
OBJ		=	$(SRC:.c=.o)
MAIN	=	main.c

all:	$(OBJ)
	@gcc -Wall -Wextra -Werror $(OBJ) $(MAIN)
clean:
	@rm $(OBJ)
fclean: clean
	@rm a.out
re:	fclean all
