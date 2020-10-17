#include "minilibx/mlx.h"
#include "src/cub3d.h"
#include "src/map_settings/map_settings.h"


int	main()
{
	t_int_coords	coords = {.x = 2, .y = 3};
	ft_printf("int coords [%d, %d]", coords.x, coords.y);
	t_coords		fcoords = {.x = (float)coords.x, .y = (float)coords.y};
	printf("float coords [%f, %f]", fcoords.x, fcoords.y);
	if (fcoords.x)
		printf("A");
}