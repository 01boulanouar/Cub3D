#include "Cupid.h"

static void	init_direction(char c, t_cube *cube)
{
	if (c == 'E')
	{
		cube->player.dir.x = 1;
		cube->player.dir.y = 0;
	}
	else if (c == 'S')
	{
		cube->player.dir.x = 0;
		cube->player.dir.y = 1;
	}
	else if (c == 'W')
	{
		cube->player.dir.x = -1;
		cube->player.dir.y = 0;
	}
	else if (c == 'N')
	{
		cube->player.dir.x = 0;
		cube->player.dir.y = -1;
	}
}

void	init_player(t_cube *cube)
{
	char	c;
	int		x;
	int		y;

	y = 0;
	while (cube->map[y])
	{
		x = 0;
		while (cube->map[y][x])
		{
			c = cube->map[y][x];
			if (ft_isin(c, "ENSW"))
			{
				cube->player.pos.x = x;
				cube->player.pos.y = y;
				init_direction(c, cube);
				return ;
			}
			x++;
		}
		y++;
	}
}
