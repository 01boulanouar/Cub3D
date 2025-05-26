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

int	key_hook(int keycode, t_cube *cube)
{
	if (keycode == ESC)
		close_window(cube);
	else if (keycode == W)
	{
		if (cube->map[cube->map_y][(int)(cube->player.pos.x + cube->player.dir.x * MOVE_SPEED)] == '0')
			cube->player.pos.x += cube->player.dir.x * MOVE_SPEED;
		if (cube->map[(int)(cube->player.pos.y + cube->player.dir.y * MOVE_SPEED)][cube->map_x] == '0')
			cube->player.pos.y += cube->player.dir.y * MOVE_SPEED;
	}
	else if (keycode == S)
	{
		if (cube->map[cube->map_y][(int)(cube->player.pos.x - cube->player.dir.x * MOVE_SPEED)] == '0')
			cube->player.pos.x -= cube->player.dir.x * MOVE_SPEED;
		if (cube->map[(int)(cube->player.pos.y - cube->player.dir.y * MOVE_SPEED)][cube->map_x] == '0')
			cube->player.pos.y -= cube->player.dir.y * MOVE_SPEED;
	}
	else if (keycode == D)
	{
		if (cube->map[cube->map_y][(int)(cube->player.pos.x + cube->player.dir.y * MOVE_SPEED)] == '0')
			cube->player.pos.x += cube->player.dir.y * MOVE_SPEED;
		if (cube->map[(int)(cube->player.pos.y + -cube->player.dir.x * MOVE_SPEED)][cube->map_x] == '0')
			cube->player.pos.y += -cube->player.dir.x * MOVE_SPEED;
	}
	else if (keycode == A)
	{
		if (cube->map[cube->map_y][(int)(cube->player.pos.x + -cube->player.dir.y * MOVE_SPEED)] == '0')
			cube->player.pos.x += -cube->player.dir.y * MOVE_SPEED;
		if (cube->map[(int)(cube->player.pos.y + cube->player.dir.x * MOVE_SPEED)][cube->map_x] == '0')
			cube->player.pos.y += cube->player.dir.x * MOVE_SPEED;
	}
	// else if (keycode == RIGHT)
	// 	{
	// 		cube->ray.dir.x = (cube->ray.dir.x * cos(-ROT_SPEED)) - (cube->ray.dir.y * sin(-ROT_SPEED)); 
	// 	}
	mlx_clear_window(cube->mlx, cube->win);
	render(cube);
	return (0);
}
