NAME		=	cub3D

OS			=	${shell echo $$OSTYPE | sed -E "s/[0-9]{0,}//g"}
LIBFT_PATH	=	libft
LIBFT		=	${LIBFT_PATH}/libft.a
CC			=	gcc
FLAGS		?=
FLAGS		+=	-Wall -Wextra -Werror
ifeq (${OS}, darwin)
	SIZE	=	${shell osascript -e 'tell application "Finder" to get bounds of window of desktop' | sed -E "s/, /|/g" | tr "|" "\n" | sed -E "1,2 s/.{0,}//g"}
	X		=	${shell echo ${SIZE} | sed -E "s/ [0-9]{0,}$$//g"}
	Y_		=	${shell echo ${SIZE} | sed -E "s/[0-9]{0,} //g"}
	Y		=	${shell echo $$((${Y_} - 125))}
	FLAGS	+=	-DSCREEN_MAX_X=${X}
	FLAGS	+=	-DSCREEN_MAX_Y=${Y}
	MLXPATH		=	minilibx_swift
	MLXDEPS		=	-I ${MLXPATH} -L ${MLXPATH} -lmlx -framework OpenGL -framework Appkit -lz
	FLAGS		+=	-DOS=1
else
	MLXPATH		=	minilibx_linux
	MLXDEPS		=	-L ${MLXPATH} -lmlx -lXext -lX11 -lm
	FLAGS		+=	-DOS=0
endif

MLX			=	${MLXPATH}/libmlx.a
SRCDIR		=	src
OBJDIR		=	obj
SRCS		=	${shell find ${SRCDIR} -name "*.c"}
OBJS		=	$(shell find ${SRCDIR} -name "*.c" | sed -E "s/^${SRCDIR}/${OBJDIR}/g" | sed -E "s/\.c$$/\.o/g")



${NAME}: ${LIBFT} ${OBJS} ${LIBMF} ${MLX}
	@${CC} -o ${NAME} ${FLAGS} ${OBJS} ${LIBFT} ${MLXDEPS}

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
	@${CC} -o ${NAME} tests.c ${MLXDEPS} ${LIBFT}

${OBJDIR}/%.o:	${SRCDIR}/%.c
	$(eval DIR := $(shell echo $@ | sed -E "s/\/[^/]+.\o$ //g"))
	@printf "compiling %s\n" "$<"
	@if [ ! -d ${DIR} ]; then\
		mkdir -p ${DIR};\
	fi
	@${CC} ${FLAGS}  -c $< -o $@

run:
	@echo 'make && (printf "\n\n\n"; ./${NAME} maps/map0.cub); printf "\n\n\n"; norminette src'