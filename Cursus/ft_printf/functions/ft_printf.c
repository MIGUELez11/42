/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 16:38:19 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/09 11:13:32 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	int		i;
	va_list	ap;

	va_start(ap, str);
	i = 0;
	while(str[i])
	{
		if (str[i] == '%')
			pf_parser(str, &i, ap);
//			i += 2;
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	return (1);
}
