/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_read_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:25:24 by mflorido          #+#    #+#             */
/*   Updated: 2019/10/20 22:56:08 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libbasic.h"
#include <stdio.h>

t_list	*ft_assign_memory(char *dict, int line)
{
	int		num_size;
	int		name_size;
	int		size;
	t_list	*node;


	name_size = sizeof(char *) * ft_g_naml(dict, line);
	num_size = sizeof(char *) * ft_g_numl(dict, line) ;
	size = num_size + name_size + sizeof(int) + sizeof(t_list *);
	node = malloc(sizeof(t_list));
	node[0].name = malloc(name_size);
	node[0].number = malloc(num_size);
	node[0].next = malloc(sizeof(t_list *));
	return (node);
}

t_list	*ft_generate_list(char *dict)
{
	int		num_lines;
	int		i;
	t_list	*list;
	t_list	*aux;

	num_lines = ft_get_dictionary_length(dict);
	i = 0;
	list = ft_assign_memory(dict, i++);
	aux = list;
	while (i < num_lines)
	{
		aux[0].next = ft_assign_memory(dict, i++);
		aux = aux[0].next;
	}
	aux[0].next = NULL;
	return (list);
}

void	ft_load_dictionary(char *dict, int line, t_list *node)
{
	int i;
	int fd;
	char a;
	int hasfindsep;
	int isrealine;

	i = 0;
	hasfindsep = 0;
	isrealine = 0;
	fd = open(dict, O_RDONLY);
	while (read(fd, &a, 1) && !(hasfindsep && a == '\n'))
	{
		if(!hasfindsep && i >= line && a >= '0' && a <= '9')
		{
			node[0].number[i-line] = a;
			i++;
		}
		else if (i >= line && a == ':')
		{
			node[0].number[i-line] = 0;
			hasfindsep = 1;
			node[0].size = i - line;
			i = line;
		}
		else if (hasfindsep && i >= line && a > ' ' && a <= '~' && a != ':')
		{
			node[0].name[i-line] = a;
			i++;
		}
		else if (i < line)
		{
			if (a > ' ' && a <= '~')
				isrealine = 1;
			else if (a == '\n' && isrealine)
			{
				i++;
				isrealine = 0;
			}
		}
	}
}

void	ft_save_dictionary(char *dict, t_list *first_node)
{
	int 	i;
	int 	lines = ft_get_dictionary_length(dict);
	t_list	*aux;

	i = 0;
	aux = first_node;
	while (i < lines) 
	{
		ft_load_dictionary(dict, i, aux);
		if (i != lines -1)
		{
			aux[0].next = ft_assign_memory(dict, i+1);
			aux = aux[0].next;
		}
		else
		{
			aux[0].next = NULL;
		}
		i++;
		
	}
}

void	free_memory(t_list *node)
{
	int i;
	t_list *aux;

	aux = node;
	while (aux[0].next != NULL)
	{
		aux = node[0].next;
	}
	free(node);
}

