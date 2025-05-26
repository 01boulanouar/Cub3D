#include "Cupid.h"

int get_pixel_color(t_img img, int x, int y)
{
	int offset;

	if (x < 0 || x >= img.width || y < 0 || y >= img.height)
		return (0);
	offset = y * img.size_line + x * (img.bits_per_pixel / 8);
	return (*(int *)(img.addr + offset));
}

void	pixel_put(t_cube *cube, int x, int y, int color)
{
	int	offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	offset = y * cube->frame.size_line + x * (cube->frame.bits_per_pixel / 8);
	*(int *)(cube->frame.addr + offset) = color;
}
