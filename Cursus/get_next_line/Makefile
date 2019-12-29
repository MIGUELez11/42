SRC	=	$(SRD)get_next_line.c \
		$(SRD)/get_next_line_utils.c 

OBD	=	obj/
SRD	=	functions/

OBJ	=	$(OBD)get_next_line.o \
		$(OBD)get_next_line_utils.o

BUFFER_SIZE	=	25

FILE = a.txt

all:	$(OBJ)
	@gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE) $(OBJ) main.c

clean:	
	@rm -rf $(OBD)
fclean:	clean
	@rm -rf a.out

$(OBD)%.o: $(SRD)%.c
	@[ -d $(OBD) ] || mkdir $(OBD)
	@gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@
re: fclean all

leaks: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out $(FILE)
