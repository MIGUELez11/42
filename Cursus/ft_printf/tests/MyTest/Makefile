# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mflorido <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 13:33:33 by mflorido          #+#    #+#              #
#    Updated: 2020/01/29 20:55:45 by mflorido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF_DIR		= ../..
PRINTFH_DIR		= ../../functions/ft_printf.h
FT_PRINTF_TEST	= ft_printf_test
PRINTF_TEST		= printf_test
SOURCE_PATH		= src
OBJ_PATH		= obj

all: clean
	@if [ ! -d $(OBJ_PATH) ]; then \
		mkdir $(OBJ_PATH); \
	fi
	@make -C $(PRINTF_DIR)
	@gcc -D PRINTFH_DIR=\"../$(PRINTFH_DIR)\" -o $(OBJ_PATH)/$(FT_PRINTF_TEST) $(PRINTF_DIR)/libftprintf.a $(SOURCE_PATH)/ft_printf.c
	@gcc -o $(OBJ_PATH)/$(PRINTF_TEST) $(SOURCE_PATH)/printf.c
	@./$(OBJ_PATH)/$(FT_PRINTF_TEST) | sed "s/$$/$$/g" >  $(FT_PRINTF_TEST)_output
	@./$(OBJ_PATH)/$(PRINTF_TEST) | sed "s/$$/$$/g" > $(PRINTF_TEST)_output
	@printf "\e[1;33mdiff $(PRINTF_TEST)_output $(FT_PRINTF_TEST)_output\e[0m\n"
	@colordiff --text $(PRINTF_TEST)_output $(FT_PRINTF_TEST)_output 2>difference || cat difference 
clean:
	@rm -rf $(OBJ_PATH)
fclean: clean
	@make -C $(PRINTF_DIR) fclean
	@rm -rf $(FT_PRINTF_TEST)_output $(PRINTF_TEST)_output difference


