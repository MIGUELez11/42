NAME		=	libftprintf.a
EXEC		=	ft_printf.out

LIBFTPATH	=	libft
LIBFT		=	$(LIBFTPATH)/libft.a

SRCDIR		=	functions
OBJDIR		=	objects

SRC			=	$(shell find functions -name "*.c")
OBJ			=	$(shell find functions -name "*.c" | sed "s/$(SRCDIR)\//$(OBJDIR)\//g" | rev | sed "s/c\./o./" | rev)

CC			=	gcc
FLAGS		+=	-Wall -Wextra -Werror
MAIN		=	main.c

RM			=	rm -rf

$(NAME):	all
all: 	$(OBJ)
	make -C $(LIBFTPATH) bonus
	@ar rcs $(NAME) $(OBJ) $(LIBFT)

c:	$(OBJ	$(OBJ)) $(NAME)
	@$(CC) $(FLAGS) -Wall -Wextra -Werror $(NAME) $(MAIN) $(LIBFT) -o $(EXEC)
	@./$(EXEC) | sed "s/$$/$$/g"

clean:
	@$(RM) $(OBJDIR)
	@make -C $(LIBFTPATH) clean

fclean:	clean
	@$(RM) $(NAME) $(EXEC)
	@make -C $(LIBFTPATH) fclean

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
	@if [ ! -d $(OBJDIR) ]; then\
		mkdir $(OBJDIR);\
	fi
	@$(CC) $(FLAGS)  -c $< -o $@

