# ------------- VARIABLES ----------------
SRCS		=	$(shell find srcs -name "*.c")
OBJS		=	$(shell find srcs -name "*.c" | rev | sed "s/c\./o\./g" | rev | sed "s/srcs/objs/g")
NAME		=	cub3d
MLX			=	libmlx.a
GNL			=	get_next_line/libgnl.a
FT_PRINTF	=	ft_printf/libftprintf.a

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
DEP			=	-I . -L . -lmlx -framework OpenGL -framework Appkit

all:		$(NAME)

# ------------- FUNCTIONS ----------------

HIDE:
	@tput civis

# ------------- DEPENDENCIES --------------
$(MLX):
	@tput civis
	@printf "\e[0;33mCompiling \e[0;34mminilibx\e[0m"
	@$(MAKE) -C minilibx 2>/dev/null>/dev/null
	@mv minilibx/$(MLX) .
	@printf "\r\e[0;32mCompiled  \e[0;34mminilibx\e[0m"

$(GNL):
	@printf "\n\e[0;33mCompiling \e[0;34mget_next_line\e[0m"
	@$(MAKE) -C get_next_line
	@printf "\r\e[0;32mCompiled  \e[0;34mget_next_line\e[0m"

$(FT_PRINTF):
	@printf "\n\e[0;33mCompiling \e[0;34mft_printf\e[0m"
	@$(MAKE) -C ft_printf
	@printf "\r\e[0;32mCompiled  \e[0;34mft_printf\e[0m"


# ------------- COMPILATION ---------------

$(NAME):	$(MLX) $(FT_PRINTF) $(OBJS) $(GNL)
	@$(CC) $(FLAGS) -o $(NAME) $(DEP) $(OBJS) $(FT_PRINTF) 
	@printf "\e[1;1H\e[2J\r\e[1;34m$(NAME)\e[1;32m successfully compiled\e[0m\n"
	@tput cnorm


objs/%.o:	srcs/%.c
	@printf "\n\r\e[0;33mCompiling \e[0;34m$<\e[0m"
	@if [ ! -d objs ]; then\
		mkdir objs;\
		mkdir objs/mf_engine;\
	fi
	@$(CC) $(FLAGS) -c $< -o $@
	@printf "\r\e[0;32mCompiled  \e[0;34m$@\e[0m"

clean:
	@printf "Ereasing \e[0;32mobjs/\e[0m"
	@rm -rf objs
	@printf "\rEreased  \e[0;31mobjs/\e[0m\n"
fclean:		clean
	@printf "Cleaning \e[0;32mminilibx\e[0m"
	@make -C minilibx clean>/dev/null
	@rm -rf $(MLX) $(NAME)
	@printf "\rCleaned  \e[0;31mminilibx\e[0m"
	@printf "\nCleaning \e[0;32mft_printf\e[0m"
	@make -C ft_printf fclean
	@printf "\Cleaned \e[0;31mft_printf\e[0m\n"
	@printf "\nCleaning \e[0;32mget_next_line\e[0m"
	@make -C get_next_line fclean
	@printf "\Cleaned \e[0;31mget_next_line\e[0m\n"
	

re:	fclean $(NAME)
