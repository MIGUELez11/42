NAME		=	cub3D
LIBFT_PATH	=	libft
LIBFT		=	${LIBFT_PATH}/libft.a
CC			=	gcc
FLAGS		?=
FLAGS		+=	-Wall -Wextra -Werror

SRCDIR		=	src
OBJDIR		=	obj
SRCS		=	${shell find ${SRCDIR} -name "*.c"}
OBJS		=	$(shell find ${SRCDIR} -name "*.c" | sed -E "s/^${SRCDIR}/${OBJDIR}/g" | sed -E "s/\.c$$/\.o/g")

MLXPATH		=	minilibx
MLX			=	${MLXPATH}/libmlx.a
MLXDEPS		=	-I ${MLXPATH} -L ${MLXPATH} -lmlx -framework OpenGL -framework Appkit


${NAME}: ${LIBFT} ${OBJS} ${LIBMF} ${MLX}
	@${CC} -g -o ${NAME} ${FLAGS} ${OBJS} ${LIBFT} ${MLXDEPS}

all: ${NAME}

${MLX}:
	@make -C ${MLXPATH}

${LIBFT}:
	@printf "Compiling libft\n"
	@make -C ${LIBFT_PATH}

clean:
	@make -C ${LIBFT_PATH} clean
	@rm -rf obj	

fclean: clean
	@make -C ${LIBFT_PATH} fclean
	@make -C ${MLXPATH} clean
	@rm -rf ${NAME}

re: fclean all

test: ${LIBFT} ${MLX}
	@gcc -o ${NAME} tests.c ${LIBFT} ${MLXDEPS}

${OBJDIR}/%.o:	${SRCDIR}/%.c
	$(eval DIR := $(shell echo $@ | sed -E "s/\/[^/]+.\o$ //g"))
	@printf "compiling %s\n" "$<"
	@if [ ! -d ${DIR} ]; then\
		mkdir -p ${DIR};\
	fi
	@${CC} ${FLAGS}  -c $< -o $@

run:
	@echo 'make && (printf "\n\n\n"; ./${NAME} maps/map0.cub); printf "\n\n\n"; norminette src'