SR1	=	get_next_line.c \
		get_next_line_utils.c

OB1	=	obj/get_next_line.o \
		obj/get_next_line_utils.o

all:	$(OB1)
	gcc -Wall -Wextra -Werror $(OB1) main.c
	

obj/%.o:	%.c	
	gcc -Wall -Wextra -Werror -c $< -o $@
clean:	
	rm -rf obj/*.o

fclean:	clean
	rm -rf a.out	
