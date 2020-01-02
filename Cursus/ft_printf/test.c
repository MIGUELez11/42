/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 20:35:44 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/02 17:14:27 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void test(char *str, ...)
{
	va_list ap;
	int		i = 0;
	int		n_args;

	if(str)
	{
		while (str[i])
		{
			if (str[i] == '%' && str[i - 1] != '%' && str[i + 1] != '%')
				n_args++;
			i++;
		}
		if (n_args == 6)
		{
			va_start(ap, str);
			printf("%d\n", va_arg(ap, int));
			printf("%s\n", va_arg(ap, char*));
			printf("%c\n", va_arg(ap, int));
			printf("%p\n", va_arg(ap, void*));
			printf("%x\n", va_arg(ap, int));
			printf("%X\n", va_arg(ap, int));
			va_end(ap);
		}
	}
}

int	ft_printf(char *str, ...);

int main()
{
	ft_printf("\e[0;31mhola que tal estas? %dYo genial%c%f%c%% hoali\n");
	ft_printf("Que tal?\033[0m");
	ft_printf("\e[1;1H\e[2J");
	ft_printf("Bien y tu?");
	return (0);
}


