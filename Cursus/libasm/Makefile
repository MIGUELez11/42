# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 15:51:48 by mflorido          #+#    #+#              #
#    Updated: 2020/11/18 23:15:19 by mflorido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a
OBJDIR		=	obj
SRCDIR		=	srcs

SRCS		=	$(SRCDIR)/ft_strlen.s\
				$(SRCDIR)/ft_strcpy.s\
				$(SRCDIR)/ft_strcmp.s\
				$(SRCDIR)/ft_write__macos.s

OBJ			=	$(OBJDIR)/ft_strlen.o\
				$(OBJDIR)/ft_strcpy.o\
				$(OBJDIR)/ft_strcmp.o\
				$(OBJDIR)/ft_write__macos.o

ASMC		=	nasm
ASMFLAGS	=	-f macho64

all: clean $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	gcc main.c $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.s
	$(ASMC) $(ASMFLAGS) $< -o $@
clean:
	rm -rf a.out libasm.a obj/*