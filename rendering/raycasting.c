#include "Cupid.h"

static void	init_delta(t_cube *cube)
{
	if (cube->ray.dir.x == 0)
		cube->ray.delta.x = 1e30;
	else
		cube->ray.delta.x = fabs(1 / cube->ray.dir.x);
	if (cube->ray.dir.y == 0)
		cube->ray.delta.y = 1e30;
	else
		cube->ray.delta.y = fabs(1 / cube->ray.dir.y);
}

static void	init_step(t_cube *cube)
{
	if (cube->ray.dir.x < 0)
	{
		cube->ray.step.x = -1;
		cube->ray.side.x = (cube->player.pos.x - cube->map_x)
			* cube->ray.delta.x;
	}
	else
	{
		cube->ray.step.x = 1;
		cube->ray.side.x = (cube->map_x + 1.0 - cube->player.pos.x)
			* cube->ray.delta.x;
	}
	if (cube->ray.dir.y < 0)
	{
		cube->ray.step.y = -1;
		cube->ray.side.y = (cube->player.pos.y - cube->map_y)
			* cube->ray.delta.y;
	}
	else
	{
		cube->ray.step.y = 1;
		cube->ray.side.y = (cube->map_y + 1.0 - cube->player.pos.y)
			* cube->ray.delta.y;
	}
}

static int	is_out_of_bound(t_cube *cube)
{
	if (cube->map_y < 0 || cube->map_y >= cube->map_length)
		return (1);
	if (cube->map_x < 0
		|| cube->map_x >= (int)ft_strlen(cube->map[cube->map_y]))
		return (1);
	return (0);
}

static void	dda(t_cube *cube)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (cube->ray.side.x < cube->ray.side.y)
		{
			cube->ray.side.x += cube->ray.delta.x;
			cube->map_x += cube->ray.step.x;
			if (cube->ray.step.x > 0)
				cube->ray.wall = EAST;
			else
				cube->ray.wall = WEST;
		}
		else
		{
			cube->ray.side.y += cube->ray.delta.y;
			cube->map_y += cube->ray.step.y;
			if (cube->ray.step.y > 0)
				cube->ray.wall = SOUTH;
			else
				cube->ray.wall = NORTH;
		}
		if (is_out_of_bound(cube) || cube->map[cube->map_y][cube->map_x] == '1')
			hit = 1;
	}
}

void	draw_line(t_cube *cube, int x)
{
	int	line_height;
	int	start;
	int	end;
	int	y;

	line_height = (int)HEIGHT / cube->ray.perp_wall;
	start = (-line_height / 2) + (HEIGHT / 2);
	if (start < 0)
		start = 0;
	end = (line_height / 2) + (HEIGHT / 2);
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	y = 0;
	while (y < start)
		pixel_put(cube, x, y++, cube->celling);
	while (y <= end)
		pixel_put(cube, x, y++, 0xFF);
	while (y < HEIGHT)
		pixel_put(cube, x, y++, cube->floor);
}

void	render(t_cube *cube)
{
	int		x;
	double	camera_x;

	cube->plane.x = 0;
	cube->plane.y = 0.66;
	x = 0;
	while (x < WIDTH)
	{
		camera_x = 2 * x / (double)WIDTH - 1;
		cube->ray.dir.x = cube->player.dir.x + (cube->plane.x * camera_x);
		cube->ray.dir.y = cube->player.dir.y + (cube->plane.y * camera_x);
		cube->map_x = (int)cube->player.pos.x;
		cube->map_y = (int)cube->player.pos.y;
		init_delta(cube);
		init_step(cube);
		dda(cube);
		if (cube->ray.wall == EAST || cube->ray.wall == WEST)
			cube->ray.perp_wall = (cube->ray.side.x - cube->ray.delta.x);
		else
			cube->ray.perp_wall = (cube->ray.side.y - cube->ray.delta.y);
		draw_line(cube, x);
		x++;
	}
	mlx_put_image_to_window(cube->mlx, cube->win, cube->frame.img, 0, 0);
}
