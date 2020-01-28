/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 07:50:53 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/28 21:23:15 by mflorido         ###   ########.fr       */
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

	printf("\e[33m------- \e[32mbasic input + char \e[33m------\e[0m\n\n");
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

	printf("\e[33m------- \e[32mbasic input + str  \e[33m------\e[0m\n\n");
	printf(", %d\n", printf("%s", NULL));
	printf(", %d\n", printf("%s", ""));
	printf(", %d\n", printf("%s", "Hola, que tal?"));
	printf(", %d\n", printf("%s", "Hola, que \0tal?"));
	printf(", %d\n", printf("%25s", "Hola, que tal?"));
	printf(", %d\n", printf("%-25s", "Hola, que tal?"));
	printf(", %d\n", printf("%*s", 25, "Hola, que tal?"));
	printf(", %d\n", printf("%*s", -25, "Hola, que tal?"));
	printf(", %d\n", printf("%-*s", 25, "Hola, que tal?"));
	//UNDEFINED printf(", %d\n", printf("%.*s", 25, "Hola, que tal?"));
	//UNDEFINED printf(", %d\n", printf("%-.*s", 25, "Hola, que tal?"));
}
