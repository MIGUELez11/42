NAME	=	libft.a
EXE		=	libft.out
SR1		=	$(shell find . -path "./part1Functions/ft_*.c")
SR2		=	$(shell find . -path "./part2Functions/ft_*.c")
SRB		=	$(shell find . -path "./bonusFunctions/ft_*.c")
OB1		=	$(SR1:.c=.o)
OB2		=	$(SR2:.c=.o)
OBB		=	$(SRB:.c=.o)

all:	$(NAME)

$(NAME): $(OB1) $(OB2)
	@ar rcs $(NAME) $(OB1) $(OB2)
clean:
	@rm -f $(OB1) $(OB2) $(OBB)
fclean:	clean
	@rm -f $(NAME)
re:		fclean all
bonus:	$(OBB)
	@ar rcs $(NAME) $(OBB)
