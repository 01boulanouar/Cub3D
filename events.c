#include "Cupid.h"

int	close_window(t_cube *cube)
{
	mlx_destroy_image(cube->mlx, cube->frame.img);
	mlx_destroy_image(cube->mlx, cube->no.img);
	mlx_destroy_image(cube->mlx, cube->so.img);
	mlx_destroy_image(cube->mlx, cube->we.img);
	mlx_destroy_image(cube->mlx, cube->ea.img);
	mlx_destroy_window(cube->mlx, cube->win);
	mlx_destroy_display(cube->mlx);
	ft_exit(EXIT_SUCCESS);
	return (0);
}
