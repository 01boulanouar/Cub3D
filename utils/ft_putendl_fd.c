#include "Cupid.h"

void	ft_putendl_fd(char *s, int fd)
{
	ssize_t	ret;

	if (!s)
		return ;
	while (*s)
		ret = write(fd, s++, 1);
	ret = write(fd, "\n", 1);
	(void)ret;
}
