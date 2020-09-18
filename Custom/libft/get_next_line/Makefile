NAME	= libgnl.a

SRC		= get_next_line.c get_next_line_utils.c
OBJ		= get_next_line.o get_next_line_utils.o

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

all: fclean $(NAME)

%.o: %.c
	@gcc -Wall -Wextra -Werror -c -o $@ $<

fclean:
	@rm -rf $(NAME)
clean:
	@rm -rf $(OBJ)