NAME	= rush-02 
LIBO	= $(shell find . -name 'lib*.o') 
LDEP	= $(shell find . -name 'lib*.c')
CC		= gcc -Wall -Wextra -Werror
DIC		= $(shell find . -name '*.dict')

rlib:	lib*.o
		@rm lib*.o

clib:	rlib	
		@clear
		@cc -c ${LDEP}

normi:
		@clear
		@norminette $(shell find . -name '*.c' -or -name '*.h')

all:	clib	
		@cc -o ${NAME} rush-02.c ${LIBO}
clean:
		@rm -f *.o
fclean: clean
		@rm -f rush-02
${NAME}: all
		 @echo "compiled"
