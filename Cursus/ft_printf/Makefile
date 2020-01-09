NAME	=	printf.out
SRCDIR	=	functions
OBJDIR	=	obj
SRC		=	$(shell find -f $(SRCDIR)/*.c)
OBJ		=	$(shell find -f $(SRCDIR)/*.c | sed "s/$(SRCDIR)\//$(OBJDIR)\//g" | tr "\.c" .o)
MAIN	=	main.c

all:	$(OBJ)
	@gcc -Wall -Wextra -Werror $(OBJ) $(MAIN) -o $(NAME)
clean:
	@rm -rf $(OBJDIR)
fclean: clean
	@rm -rf $(NAME)
re:	fclean all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@[ -d $(OBJDIR)/ ] || mkdir $(OBJDIR)/
	@gcc -Wall -Wextra -Werror -c $< -o $@
