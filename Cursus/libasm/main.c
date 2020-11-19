/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 09:22:14 by mflorido          #+#    #+#             */
/*   Updated: 2020/11/19 00:16:05 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <unistd.h>

void	print_header(const char *color, const char *str)
{
	size_t	len;
	size_t	slen;
	size_t	half;
	size_t	i;

	if (!str)
		return ;
	len = 78;
	slen = strlen(str);
	if (len - 1 <= slen)
		len = slen + 6;
	half = (len - slen) / 2;
	i = 0;
	if (color)
		printf("%s", color);
	while (i < half)
	{
		printf("=");
		i++;
	}
	printf(" %s ", str);
	i += slen;
	while (i < len)
	{
		printf("=");
		i++;
	}
	printf("\e[0m\n");
}
void	check_strlen(const char *str)
{
	size_t	o_len;
	size_t	f_len;

	printf("Test:\n");
	o_len = strlen(str);
	f_len = ft_strlen(str);
	if (f_len == o_len)
		printf("\e[1;32m");
	else
		printf("\e[1;31m");
	printf("   Expected: '%ld' to equal: '%ld'\e[0m\n", f_len, o_len);
}

void	check_strcpy(char *dst, const char *src)
{
	char	*o_ret;
	char	*f_ret;
	char	*dst_cpy;
	char	*src_cpy;

	// if (!dst)
	// 	dst_cpy = 0;
	// else
	printf("Test:\n");
	o_ret = strcpy(dst, src);
	f_ret = ft_strcpy(dst, src);
	if (!strcmp(o_ret, f_ret) && !strcmp(dst, o_ret))
		printf("\e[1;32m");
	else
		printf("\e[1;31m");
	printf("   Expected return: '%s' to equal: '%s'\n", f_ret, o_ret);
	printf("   Expected dst: '%s' to equal: '%s'\e[0m\n", dst, src);

}

int 	main() {
	print_header("\e[1;33m", "Tests for ft_strlen");
	check_strlen("Hola");
	check_strlen("Qué tal?");
	check_strlen("H\0f");
	check_strlen("J\e[1;33m\e[0m\n\033");
	check_strlen("Adios\n");
	check_strlen("Hi!");
	print_header("\e[1;33m", "Tests for ft_strcpy");
	{
		char dst[5];
		check_strcpy(dst, "Hola");
	}
	{
		char dst[5];
		check_strcpy(dst, "H\0ola");
	}
	{
		char dst[3];
		check_strcpy(dst, "");
	}
	{
		char dst[27];
		check_strcpy(dst, "Adios carambola\0loca");
	}

}