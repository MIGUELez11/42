/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 07:50:53 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/19 20:17:53 by miguelez1        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions/ft_printf.h"

int	ft_printf(const char *str, ...);

int main()
{
	write(1,"\e[1;34m--------- \e[1;31m ft_printf \e[1;34m----------\e[0m\n", 57);

	ft_printf("\e[1;33m[Clean String]\e[0m Hola\n");
	ft_printf("\e[1;33m[Clean Long String]\e[0m hola que tal estas?\n");

	ft_printf("\e[1;33m[String + char]\e[0m hola %c\n", 'M');
	ft_printf("\e[1;33m[String + 3char]\e[0m hola %c%c%c\n", 'q', 'u', 'e');
	ft_printf("\e[1;33m[String + char(w)]\e[0m hola, que tal %5c\n", '?');
	ft_printf("\e[1;33m[String + char(-w)]\e[0m hola, que tal %-5c\n", '?');
	ft_printf("\e[1;33m[String + char(*)]\e[0m hola, que tal %*c\n", 5, '?');
	ft_printf("\e[1;33m[String + char(-*)]\e[0m hola, que tal %*c\n", -5, '?');

	ft_printf("\e[1;33m[String + string]\e[0m hola %s\n", "que tal?");
	ft_printf("\e[1;33m[String + 3string]\e[0m hola %s%s%s\n", "que", " tal", " estas?");
	ft_printf("\e[1;33m[String + string(w)]\e[0m hola, que tal %5s\n", "?");
	ft_printf("\e[1;33m[String + string(w)]\e[0m hola, que tal %5s\n", " estas?");
	ft_printf("\e[1;33m[String + string(-w)]\e[0m hola, que tal %-5s\n", "?");
	ft_printf("\e[1;33m[String + string(-w)]\e[0m hola, que tal %-5s\n", " estas?");
	ft_printf("\e[1;33m[String + string(*)]\e[0m hola, que tal %*s\n", 5, "?");
	ft_printf("\e[1;33m[String + string(*)]\e[0m hola, que tal %*s\n", 5, " estas?");
	ft_printf("\e[1;33m[String + string(-*)]\e[0m hola, que tal %*s\n", -5, "?");
	ft_printf("\e[1;33m[String + string(-*)]\e[0m hola, que tal %*s\n", -5, " estas?");



	printf("\e[1;34m--------- \e[1;31m  printf   \e[1;34m----------\e[0m\n");

	printf("\e[1;33m[Clean String]\e[0m Hola\n");
	printf("\e[1;33m[Clean Long String]\e[0m hola que tal estas?\n");

	printf("\e[1;33m[String + char]\e[0m hola %c\n", 'M');
	printf("\e[1;33m[String + 3char]\e[0m hola %c%c%c\n", 'q', 'u', 'e');
	printf("\e[1;33m[String + char(w)]\e[0m hola, que tal %5c\n", '?');
	printf("\e[1;33m[String + char(-w)]\e[0m hola, que tal %-5c\n", '?');
	printf("\e[1;33m[String + char(*)]\e[0m hola, que tal %*c\n", 5, '?');
	printf("\e[1;33m[String + char(-*)]\e[0m hola, que tal %*c\n", -5, '?');

	printf("\e[1;33m[String + string]\e[0m hola %s\n", "que tal?");
	printf("\e[1;33m[String + 3string]\e[0m hola %s%s%s\n", "que", " tal", " estas?");
	printf("\e[1;33m[String + string(w)]\e[0m hola, que tal %5s\n", "?");
	printf("\e[1;33m[String + string(w)]\e[0m hola, que tal %5s\n", " estas?");
	printf("\e[1;33m[String + string(-w)]\e[0m hola, que tal %-5s\n", "?");
	printf("\e[1;33m[String + string(-w)]\e[0m hola, que tal %-5s\n", " estas?");
	printf("\e[1;33m[String + string(*)]\e[0m hola, que tal %*s\n", 5, "?");
	printf("\e[1;33m[String + string(*)]\e[0m hola, que tal %*s\n", 5, " estas?");
	printf("\e[1;33m[String + string(-*)]\e[0m hola, que tal %*s\n", -5, "?");
	printf("\e[1;33m[String + string(-*)]\e[0m hola, que tal %*s\n", -5, " estas?");

}
