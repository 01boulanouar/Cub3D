#include "Cupid.h"

int	ft_isallspace(char *str)
{
	size_t	i;
	
	if (!str)
		return (0);
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	return (i == ft_strlen(str));
}
