/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uppercase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelez1 <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:27:07 by miguelez1         #+#    #+#             */
/*   Updated: 2020/02/09 16:48:19 by miguelez1        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "o_libft.h"

void	ft_uppercase(char *str)
{
	int	i;

	i = strlen(str);
	if (!str)
		return ;
	while (i >= 0)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] += 'A' - 'a';
		i--;
	}
}
