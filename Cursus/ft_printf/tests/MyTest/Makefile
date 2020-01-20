# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mflorido <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 13:33:33 by mflorido          #+#    #+#              #
#    Updated: 2020/01/20 18:34:51 by mflorido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF_DIR		= ../..
PRINTFH_DIR		= ../../functions/ft_printf.h
FT_PRINTF_TEST	= ft_printf_test
PRINTF_TEST		= printf_test

all:
	@make -C $(PRINTF_DIR)
	@gcc -o $(FT_PRINTF_TEST) $(PRINTF_DIR)/libftprintf.a ft_printf.c
	@gcc -o $(PRINTF_TEST) printf.c
	@./$(FT_PRINTF_TEST) | sed "s/$$/$$/g" >  $(FT_PRINTF_TEST)_output
	@./$(PRINTF_TEST) | sed "s/$$/$$/g" > $(PRINTF_TEST)_output
	diff $(PRINTF_TEST)_output $(FT_PRINTF_TEST)_output





