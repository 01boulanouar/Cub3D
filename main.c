#include "Cupid.h"

void	init_mlx(t_cube *cube)
{
	cube->mlx = mlx_init();
	if (!cube->mlx)
		ft_exit(EXIT_FAILURE);
	cube->win = mlx_new_window(cube->mlx, WIDTH, HEIGHT, TITLE);
	if (!cube->win)
		ft_exit(EXIT_FAILURE);
	cube->frame.img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	if (!cube->frame.img)
		ft_exit(EXIT_FAILURE);
	cube->frame.addr = mlx_get_data_addr(cube->frame.img,
			&(cube->frame.bits_per_pixel), &(cube->frame.size_line),
			&(cube->frame.endian));
	if (!cube->frame.addr)
		ft_exit(EXIT_FAILURE);
	mlx_hook(cube->win, CLOSE_BUTTON, 0, close_window, cube);
}

int	main(int argc, char **argv)
{
	t_cube	cube;

	init_mlx(&cube);
	parse(argc, argv, &cube);
	init_player(&cube);
	render(&cube);
	mlx_loop(cube.mlx);
	ft_free();
	return (EXIT_SUCCESS);
}
