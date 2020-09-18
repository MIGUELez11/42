/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflorido <mflorido@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 14:30:29 by mflorido          #+#    #+#             */
/*   Updated: 2020/09/04 16:29:01 by mflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct	s_config
{
	int		x;
	int		y;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	char	*f;
	char	*c;
}				t_config;


/*
** int	cb_mainLoop(t_args *args)
** {
** 	static unsigned int frame = 0;
** 	if (frame == 0)
** 	{
** 	}
** 	if (frame % 60 == 0)
** 	{
** 		mlx_mouse_move(args->window, args->windowP.x/2, args->windowP.y/2);
** 		args++;
** 	}
** 	frame++;
** 	return (1);
** }
** int	endGame(t_args *args)
** {
** 	ft_printf("game ended");
** 	if (args->mlx && args->window)
** 	{
** 		mlx_destroy_window(args->mlx, args->window);
** //		free(args->mlx);
** //		args->mlx = 0;
** 		args->window = 0;
** 		exit(0);
** 	}
** 	return (1);
** }
**
** int	cb_onMouseMovement(int x, int y, t_args *args)
** {
** 	args++;
** 	printf("mouse_x = 5 mouse_x%4d, mouse_y = %4d\n", x, y);
** 	return (1);
** }
**
**
** int main()
** {
** 	t_args	args;
**
** 	args.windowP.x = 500;
** 	args.windowP.y = 500;
** 	strcpy(args.windowP.name, "Cub3d");
** 	args.KeyPress = cb_onKeypress;
** 	args.KeyRelease = cb_onKeyrelease;
** 	args.MouseMove = cb_onMouseMovement;
** 	args.Exit = endGame;
** 	args.Main = cb_mainLoop;
** 	mf_start(&args);
** }
*/

void	get_config(int fd) {
	t_config	config;
	char		*line;

	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		if (line[0] == 'R')
		{
			config.no = ft_substr(line, 2, ft_strlen(line) - 2);
			printf("\n\nR: %s\n\n", config.no);
			free(config.no);
		}
		free(line);
	}
	if (line)
	{
		printf("%s\n", line);
		free(line);
	}
}

int		validate_first_argument(char *name)
{
	char	*extension;
	int		fd;
	int		is_valid;

	extension = ft_substr(name, ft_strlen(name) - 4, 4);
	is_valid = ft_strncmp(".cub", extension, 4) == 0;
	free(extension);
	if (is_valid)
	{
		
		get_config(fd = open(name, 0));
		close(fd);
	}
	return (is_valid);
}

int		main(int argc, char **argv)
{
	ft_printf("%d %s\n", argc, argv[1]);
	validate_first_argument(argv[1]);
	printf("====================================\n");
	system("leaks cub3d");
	return (0);
}
