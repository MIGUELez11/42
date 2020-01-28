/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 07:50:53 by mflorido          #+#    #+#             */
/*   Updated: 2020/01/28 21:13:09 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFH_DIR
# error "ft_printf.h not found, edit your Makefile"
#endif

#include PRINTFH_DIR

void	putnmbr(int num)
{
	long int	n;
	char		c;

	n = num;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		putnmbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}
void	putnbr(int num)
{
	write(1, ", ", 2);
	putnmbr(num);
	write(1, "\n", 1);
}



int main()
{
	write(1, "\e[33m---------- \e[32mbasic input \e[33m----------\e[0m\n\n", 54);
	//UNDEFINED putnbr(ft_printf(NULL));
	putnbr(ft_printf(""));
	putnbr(ft_printf("Hello World!"));
	putnbr(ft_printf("Hello World. How are you tonight. This is a test"));
	write(1, "\e[33m------- \e[32mbasic input + char \e[33m------\e[0m\n\n", 54);
	putnbr(ft_printf("%c", 'a'));
	putnbr(ft_printf("%c", '\0'));
	putnbr(ft_printf("%5c", 'a'));
	putnbr(ft_printf("%-5c", 'a'));
	putnbr(ft_printf("%*c", 5, 'a'));
	putnbr(ft_printf("%-*c", 5, 'a'));
	putnbr(ft_printf("%*c", -5, 'a'));
	putnbr(ft_printf("hola que tal? %*c", -5, 'B'));
	putnbr(ft_printf("%*c%*c%-*c", -5, 'a', 2, 'b', 6, 'c'));
	/*//UNDEFINED */putnbr(ft_printf("%.5c", 'a'));
	//UNDEFINED putnbr(ft_printf("%-.5c", 'a'));

	write(1, "\e[33m------- \e[32mbasic input + str  \e[33m------\e[0m\n\n", 54);
	putnbr(ft_printf("%s", NULL));
	putnbr(ft_printf("%s", ""));
	putnbr(ft_printf("%s", "Hola, que tal?"));
	putnbr(ft_printf("%s", "Hola, que \0tal?"));
	putnbr(ft_printf("%25s", "Hola, que tal?"));
	putnbr(ft_printf("%-25s", "Hola, que tal?"));
	putnbr(ft_printf("%*s", 25, "Hola, que tal?"));
	putnbr(ft_printf("%*s", -25, "Hola, que tal?"));
	putnbr(ft_printf("%-*s", 25, "Hola, que tal?"));
}
