/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 20:35:44 by mflorido          #+#    #+#             */
/*   Updated: 2019/12/31 22:49:58 by marvin           ###   ########.fr       */
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

int main()
{
	test("%d %s %c %p %x %X %%", 12, "hola que tal estas?", 'z', NULL, 93, 93);
	return (0);
}


