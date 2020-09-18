NAME		=	cub3d
LIBFT_PATH	=	libft
LIBFT		=	${LIBFT_PATH}/libft.a
CC			=	gcc
FLAGS		=	
FLAGS		+=	-Wall -Wextra -Werror

SRCDIR		=	src
OBJDIR		=	obj
SRCS		=	${shell find ${SRCDIR} -name "*.c"}
OBJS		=	$(shell echo ${SRCS} | sed "s/$(SRCDIR)\//$(OBJDIR)\//g" | rev | sed "s/c\./o./" | rev)

${NAME}: ${LIBFT} ${OBJS}
	@${CC} -o ${NAME} ${FLAGS} ${OBJS} ${LIBFT}

all: ${NAME}

${LIBFT}:
	@printf "Compiling libft\n"
	@make -C ${LIBFT_PATH}

clean:
	@make -C ${LIBFT_PATH} clean
	@rm -rf obj	

fclean: clean
	@make -C ${LIBFT_PATH} fclean
	@rm -rf ${NAME}

re: fclean all

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
	@printf "compiling %s\n" "$<"
	@if [ ! -d $(OBJDIR) ]; then\
		mkdir $(OBJDIR);\
	fi
	@$(CC) $(FLAGS)  -c $< -o $@