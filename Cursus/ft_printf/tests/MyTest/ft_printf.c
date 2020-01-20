/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 07:50:53 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/20 18:55:51 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../functions/ft_printf.h"

int main()
{
	//ft_printf("\e[1;34m-------------- \e[1;31m ft_printf \e[1;34m---------------\e[0m\n\n");

	ft_printf("\e[1;35m-------------- \e[1;31m  No Args  \e[1;35m---------------\e[0m\n");
	ft_printf("\e[1;33m[Clean String]\e[0m Hola\n");
	ft_printf("\e[1;33m[Clean Long String]\e[0m hola que tal estas?\n");

	ft_printf("\e[1;35m-------------- \e[1;31m Char Arg  \e[1;35m---------------\e[0m\n");
	ft_printf("\e[1;33m[String + char]\e[0m hola %c\n", 'M');
	ft_printf("\e[1;33m[String + 3char]\e[0m hola %c%c%c\n", 'q', 'u', 'e');
	ft_printf("\e[1;33m[String + char(w)]\e[0m hola, que tal %5c\n", '?');
	ft_printf("\e[1;33m[String + char(-w)]\e[0m hola, que tal %-5c\n", '?');
	ft_printf("\e[1;33m[String + char(*)]\e[0m hola, que tal %*c\n", 5, '?');
	ft_printf("\e[1;33m[String + char(-*)]\e[0m hola, que tal %*c\n", -5, '?');

	ft_printf("\e[1;35m-------------- \e[1;31m  Str Arg  \e[1;35m---------------\e[0m\n");
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
	ft_printf("\e[1;33m[String + string(p)]\e[0m hola, que tal %.5s\n", " estas?");
	ft_printf("\e[1;33m[String + string(p=0)]\e[0m hola, que tal %.0s\n", " estas?");
	ft_printf("\e[1;33m[String + string(wp)]\e[0m hola, que tal %6.3s\n", " estas?");
	ft_printf("\e[1;33m[String + string(-wp)]\e[0m hola, que tal %-6.3s\n", " estas?");
	ft_printf("\e[1;33m[String + string(-*.*)]\e[0m hola, que tal %-*.*s\n", 6, 3," estas?");
	ft_printf("\e[1;33m[String + string(NULL)]\e[0m hola, que tal %s\n", NULL);


	ft_printf("\e[1;35m-------------- \e[1;31m  Int Arg  \e[1;35m---------------\e[0m\n");
	ft_printf("\e[1;33m[String + int]\e[0m hola, que tal %d\n", 42);
	ft_printf("\e[1;33m[String + int(w)]\e[0m hola, que tal %5d\n", 42);
	ft_printf("\e[1;33m[String + int(-w)]\e[0m hola, que tal %-5d\n", 42);
	ft_printf("\e[1;33m[String + int(p)]\e[0m hola, que tal %.1d\n", 42);
	ft_printf("\e[1;33m[String + int(p)]\e[0m hola, que tal %.5d\n", 42);
	ft_printf("\e[1;33m[String + int(-p)]\e[0m hola, que tal %-.5d\n", 42);
	ft_printf("\e[1;33m[String + int(*.*)]\e[0m hola, que tal %*.*d\n", 5, 5, 42);
	ft_printf("\e[1;33m[String + int(*)]\e[0m hola, que tal %*d\n", 5, 42);
	ft_printf("\e[1;33m[String + int(-*)]\e[0m hola, que tal %*d\n", -5, 42);
	ft_printf("\e[1;33m[String + int(0)]\e[0m hola, que tal %010d\n", 42);
	ft_printf("\e[1;33m[String + int(-0)]\e[0m hola, que tal %-010d\n", 42);
}
