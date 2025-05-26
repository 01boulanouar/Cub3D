#include "Cupid.h"

void	ft_error(char *message)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	ft_exit(EXIT_FAILURE);
}
