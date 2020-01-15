/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 07:50:53 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/15 20:50:21 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions/ft_printf.h"

int main()
{
	write(1,"\e[1;34m--------- \e[1;31m ft_printf \e[1;34m----------\e[0m\n", 57);
	ft_printf("\e[1;33m[Clean String]\e[0m Hola\n");
	ft_printf("\e[1;33m[Clean Long String]\e[0m hola que tal estas?\n");
	ft_printf("\e[1;33m[String + char]\e[0m hola %c\n", 'M');
	ft_printf("\e[1;33m[String + 3char]\e[0m hola %c%c%c\n", 'q', 'u', 'e');
	ft_printf("\e[1;33m[String + char(width)]\e[0m hola, que tal %5c\n", '?');

	printf("\e[1;34m--------- \e[1;31m  printf   \e[1;34m----------\e[0m\n");
	printf("\e[1;33m[Clean String]\e[0m Hola\n");
	printf("\e[1;33m[Clean Long String]\e[0m hola que tal estas?\n");
	printf("\e[1;33m[String + char]\e[0m hola %c\n", 'M');
	printf("\e[1;33m[String + 3char]\e[0m hola %c%c%c\n", 'q', 'u', 'e');
	printf("\e[1;33m[String + char(width)]\e[0m hola, que tal %5c\n", '?');

	write(2, "Error", 5);
}
