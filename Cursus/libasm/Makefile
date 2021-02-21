# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 15:51:48 by mflorido          #+#    #+#              #
#    Updated: 2020/11/23 23:28:44 by mflorido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a
OBJDIR		=	obj
SRCDIR		=	srcs

SRCS		=	$(SRCDIR)/ft_strlen.s\
				$(SRCDIR)/ft_strcpy.s\
				$(SRCDIR)/ft_strcmp.s\
				$(SRCDIR)/ft_write__macos.s\
				$(SRCDIR)/ft_read__macos.s\
				$(SRCDIR)/ft_strdup.s

OBJ			=	$(OBJDIR)/ft_strlen.o\
				$(OBJDIR)/ft_strcpy.o\
				$(OBJDIR)/ft_strcmp.o\
				$(OBJDIR)/ft_write__macos.o\
				$(OBJDIR)/ft_read__macos.o\
				$(OBJDIR)/ft_strdup.o

ASMC		=	nasm
ASMFLAGS	=	-f macho64

all: clean $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.s
	@if [ ! -d $(OBJDIR) ];\
	then\
		mkdir -p $(OBJDIR);\
	fi
	$(ASMC) $(ASMFLAGS) $< -o $@

clean:
	rm -rf obj

fclean:	clean
	rm -rf $(NAME) a.out