/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_read_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 21:59:26 by mflorido          #+#    #+#             */
/*   Updated: 2019/10/20 23:29:34 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libbasic.h"
#include <stdlib.h>
#include "stdio.h"

int		ft_cmpstr(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i])
	{
		if (str1[i] != str2[i])
			break;
		i++;
	}
	if (str1[i] == 0 && str2[i] == 0)
		return (1);
	return (0);


}

void	ft_find_coincidence(char *num, int size, t_list *list)
{
	int i;
	int found;

	i = 0;
	found = 0;
	while (1)
	{

		if (list[0].size == size)
		{
			if (ft_cmpstr(num, list[0].number)) 
			{
				found = 1;
				i = 0;
				while (list[0].name[i])
					write(1, &list[0].name[i++],1);
			}
		}
		if (found)
			break;
		else if (list[0].next != NULL)
			list = list[0].next;
		else
			break;
	}
}
char	*ft_gen_num(char num, int size)
{
	int i;
	char *n;

	n = malloc(sizeof(char)*size);
	n[0] = num;
	i = 1;
	while (i < size)
		n[i++] = '0';
	return (n);
	
}
void	ft_split_num(char *num, int size, t_list *list)
{
		if (size > 2)
		{
			ft_find_coincidence(ft_gen_num(num[0], 1), 1, list);
			write(1, " ", 1);
			ft_find_coincidence(ft_gen_num(num[0], size) ,size, list);
		}
		else if (size == 2)
		{
			ft_find_coincidence(ft_gen_num(num[0], 2), 2, list);
			write(1, " ", 1);
			ft_split_num(&num[1], 1, list);
		}
		else
		{
			ft_find_coincidence(num, 1, list);
		}
}
