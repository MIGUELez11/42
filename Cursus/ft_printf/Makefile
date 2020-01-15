NAME		=	libftprintf.a
EXEC		=	ft_printf.out

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
	@ar rcs $(NAME) $(OBJ)

c:	$(NAME)
	@$(CC) $(FLAGS) -Wall -Wextra -Werror $(NAME) $(MAIN) -o $(EXEC)

clean:
	$(RM) $(OBJDIR)

fclean:	clean
	$(RM) $(NAME) $(EXEC)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
	@if [ ! -d $(OBJDIR) ]; then\
		mkdir $(OBJDIR);\
	fi
	@$(CC) $(FLAGS)  -c $< -o $@

