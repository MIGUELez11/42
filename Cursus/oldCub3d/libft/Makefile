NAME		= libft.a

PRINTF		= ft_printf/libftprintf.a
GNL			= get_next_line/libgnl.a

$(NAME): $(GNL) $(PRINTF)
	@cp $(PRINTF) $(NAME)
	@ar x $(GNL)
	@ar rcs $(NAME) *.o
	@rm -rf *.o __.SYMDEF\ SORTED

$(PRINTF):
	@make -C ft_printf fclean
	@make -C ft_printf

$(GNL):
	@make -C get_next_line fclean
	@make -C get_next_line
	
ALL: fclean $(NAME)

clean:
	@make -C ft_printf clean
	@make -C get_next_line clean
	@make -C ft_printf/libft clean
fclean: clean
	@make -C ft_printf fclean
	@make -C get_next_line fclean
	@make -C ft_printf/libft fclean
	@rm -rf $(NAME)