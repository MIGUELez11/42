/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 07:50:53 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/29 20:43:20 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 

int main()
{
	printf("\e[33m---------- \e[32mbasic input \e[33m----------\e[0m\n\n");
	//UNDEFINED printf(", %d\n", printf(NULL));
	printf(", %d\n", printf(""));
	printf(", %d\n", printf("Hello World!"));
	printf(", %d\n", printf("Hello World. How are you tonight. This is a test"));

	printf("\e[33m----------- \e[32mchar input \e[33m----------\e[0m\n\n");
	printf(", %d\n", printf("%c", 'a'));
	printf(", %d\n", printf("%c", '\0'));
	printf(", %d\n", printf("%5c", 'a'));
	printf(", %d\n", printf("%-5c", 'a'));
	printf(", %d\n", printf("%*c", 5, 'a'));
	printf(", %d\n", printf("%-*c", 5, 'a'));
	printf(", %d\n", printf("%*c", -5, 'a'));
	printf(", %d\n", printf("hola que tal? %*c", -5, 'B'));
	printf(", %d\n", printf("%*c%*c%-*c", -5, 'a', 2, 'b', 6, 'c'));
	//UNDEFINED printf(", %d\n", printf("%.5c", 'a'));
	//UNDEFINED printf(", %d\n", printf("%-.5c", 'a'));

	printf("\e[33m----------- \e[32mstr input \e[33m-----------\e[0m\n\n");
	printf(", %d\n", printf("%s", NULL));
	printf(", %d\n", printf("%s", ""));
	printf(", %d\n", printf("%s", "Hola, que tal?"));
	printf(", %d\n", printf("%s", "Hola, que \0tal?"));
	printf(", %d\n", printf("%25s", "Hola, que tal?"));
	printf(", %d\n", printf("%-25s", "Hola, que tal?"));
	printf(", %d\n", printf("%*s", 25, "Hola, que tal?"));
	printf(", %d\n", printf("%*s", -25, "Hola, que tal?"));
	printf(", %d\n", printf("%-*s", 25, "Hola, que tal?"));
	printf(", %d\n", printf("%.*s", 4, "Hola, que tal?"));
	printf(", %d\n", printf("%-.*s", 4, "Hola, que tal?"));
	printf(", %d\n", printf("%.*s", -4, "Hola, que tal?"));

	printf("\e[33m----------- \e[32mint input \e[33m-----------\e[0m\n\n");
	printf(", %d\n", printf("%d", 0));
	printf(", %d\n", printf("%d", 1));
	printf(", %d\n", printf("%d", -1));
	printf(", %d\n", printf("%d", 10));
	printf(", %d\n", printf("%d", -10));
	printf(", %d\n", printf("%d", 42));
	printf(", %d\n", printf("%d", -42));
	printf(", %d\n", printf("%d", 2147483647));
	printf(", %d\n", printf("%d", -2147483648));
	printf(", %d\n", printf("%0d", 42));
	printf(", %d\n", printf("%-d", 42));
	printf(", %d\n", printf("%5d", 42));
	printf(", %d\n", printf("%-5d", 42));
	printf(", %d\n", printf("%*d", 5, 42));
	printf(", %d\n", printf("%-*d", 5,  42));
	printf(", %d\n", printf("%*d", -5, 42));
	printf(", %d\n", printf("%5d", 42));
	printf(", %d\n", printf("%-5d", 42));
	printf(", %d\n", printf("%*d", 5, 42));
	printf(", %d\n", printf("%-*d", 5,  42));
	printf(", %d\n", printf("%*d", -5, 42));
	printf(", %d\n", printf("%.5d", 42));
	printf(", %d\n", printf("%-.5d", 42));
	printf(", %d\n", printf("%.*d", 5,  42));
	printf(", %d\n", printf("%-.*d", 5,  42));
	printf(", %d\n", printf("%.*d", -5, 42));
	printf(", %d\n", printf("%5.5d", 42));
	printf(", %d\n", printf("%-5.5d", 42));
	printf(", %d\n", printf("%*.5d", 5, 42));
	printf(", %d\n", printf("%-*.5d", 5,  42));
	printf(", %d\n", printf("%*.5d", -5, 42));
	printf(", %d\n", printf("%5.*d", 5,  42));
	printf(", %d\n", printf("%-5.*d", 5,  42));
	printf(", %d\n", printf("%5.*d", -5,  42));
	printf(", %d\n", printf("%*.*d", 5, 5, 42));
	printf(", %d\n", printf("%-*.*d", 5, 5, 42));
	printf(", %d\n", printf("%*.*d", -5, -5, 42));
	printf(", %d\n", printf("%05.5d", 42));
	printf(", %d\n", printf("%0*.*d", 5, 5, 42));
	printf(", %d\n", printf("%0*.*d", -5, -5, 42));
}
