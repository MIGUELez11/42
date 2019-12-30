/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 20:35:44 by mflorido          #+#    #+#             */
/*   Updated: 2019/12/30 20:57:15 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void test(int n_args, ...)
{
	va_list ap;
	int r = 0;
	int i = 0;

	va_start(ap, n_args);
	while(i < n_args)
	{
		r += va_arg(ap, int);
		i++;
	}
	printf("%d", r);
}

int main()
{
	//test(2, 'n', 'n');
printf("%x %X", 932453, 932453);
	return (0);
}


