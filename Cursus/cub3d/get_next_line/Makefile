GNL		=	libgnl.a
CC		=	clang
FLAGS	=	-Wall -Wextra -Werror
OBJS	=	get_next_line.o get_next_line_utils.o

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
$(GNL): $(OBJS)
	@ar rcs $(GNL) $(OBJS)
clean:
	@rm -rf $(OBJS)
fclean: clean
	@rm -rf $(GNL)

re: fclean $(GNL)