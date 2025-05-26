#include "Cupid.h"

void	ft_putstr_fd(const char *s, int fd)
{
	int	ret;

	if (!s)
		return ;
	while (*s)
		ret = write(fd, s++, 1);
	(void)ret;
}
