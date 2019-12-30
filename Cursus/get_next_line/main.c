<<<<<<< HEAD
int main()
{
	
}
=======
#include "functions/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

static int	ft_intlen(int n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		if (n != 0)
			i++;
	}
	return (++i);
}

char		*ft_itoa(int n)
{
	int			i;
	char		*r;
	long int	n2;
	int			isneg;

	i = 1;
	isneg = 0;
	i = ft_intlen(n);
	isneg = (n < 0 ? 1 : 0);
	n2 = (n < 0 ? -(long)n : n);
	i += (isneg ? 1 : 0);
	r = malloc(i + 1 * sizeof(char));
	if (r == NULL)
		return (NULL);
	r[i--] = 0;
	while (i >= (isneg == 0 ? 0 : 1))
	{
		r[i] = n2 % 10 + '0';
		n2 /= 10;
		i--;
	}
	r[0] = (isneg ? '-' : r[0]);
	return (r);
}

int main(int argc, char **argv)
{
	char	*str;
	int 	file = 1;
	int		fd = -1;
	int		lines = 0;
	int		output = open("output", O_WRONLY);
	char	*aux;
	int		error = -2;

	if (output == -1)
	{
		printf("\033[0;31mOutput file can't be opened\n\033[0m");
		return (-1);
	}
	while (file < argc)
	{
		fd = open(argv[file], O_RDONLY);
		if (fd != -1)
		{
			printf("\e[1;1H\e[2J");
			lines = 0;
			while((error = get_next_line(fd, &str)) > 0)
			{
				printf("%s\n", str);
				free(str);
				str = NULL;
				lines++;
			}
			if (error > -1)
			{
				printf("%s\n", str);
				lines++;
				printf("\033[0;32mfile %4d/%d was read with %d lines\n\033[0m", file, argc - 1, lines);
				free(str);
				str = NULL;
				write(output, "file \"", 6);
				if (argv[file])
					write(output, argv[file], strlen(argv[file]));
				write(output, "\" ",2);
				aux = ft_itoa(file);
				write(output, aux, strlen(aux));
				free(aux);
				write(output, "/", 1);
				aux = ft_itoa(argc - 1);
				write(output, aux, strlen(aux));
				free(aux);
				write(output, " read with ", 11);
				aux = ft_itoa(lines);
				write(output, aux, strlen(aux));
				free(aux);
				write(output, " lines\n", 7);
			}
			else if (error == -1)
			{
				printf("\033[0;31mfile %4d/%d can't be reaf\n\033[0m", file, argc - 1);
				write(output, "!file ", 6);
				aux = ft_itoa(file);
				write(output, aux, strlen(aux));
				free(aux);
				write(output, "/", 1);
				aux = ft_itoa(argc - 1);
				write(output, aux, strlen(aux));
				free(aux);
				write(output, " can't be read\n", 17);
			}
			close(fd);
		}
		else
		{
			printf("\033[0;31mfile %4d/%d not opened\n\033[0m", file, argc - 1);
			write(output, "!file ", 6);
				aux = ft_itoa(file);
				write(output, aux, strlen(aux));
				free(aux);
				write(output, "/", 1);
				aux = ft_itoa(argc - 1);
				write(output, aux, strlen(aux));
				free(aux);
				write(output, " can't be opened\n", 17);
		}
		file++;
	}
}
>>>>>>> 7f8e281809262605cca8d644bf7737c27d2c8ec6
