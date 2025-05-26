#include "Cupid.h"

static void	valid_format(char *str)
{
	int	i;

	i = 1;
	while (*str)
	{
		if (*str == ',')
			i++;
		str++;
	}
	if (i != 3)
		ft_error("Invalid color format (R,G,B)");
}

int	valid_number(char *str)
{
	size_t	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isspace(str[i]))
		i++;
	if (i < ft_strlen(str) || ft_isallspace(str)
		|| (ft_strlen(str) == 1 && (str[0] == '-' || str[0] == '+' ))
		|| ft_atol(str) == LONG_MAX + 1ul)
		return (0);
	if ((long) ft_atol(str) < 0 || (long) ft_atol(str) > 255)
		return (0);
	return (1);
}

void	init_rgb(char *str, unsigned int *rgb)
{
	char	**split;

	if (!*str)
		return ;
	valid_format(str);
	split = ft_split(str, ',');
	if (!split)
		ft_error("Failed to split color");
	if (!valid_number(split[0])
		|| !valid_number(split[1])
		|| !valid_number(split[2]))
		ft_error("Invalid RGB value");
	*rgb = (ft_atol(split[0]) << 16) | (ft_atol(split[1]) << 8) | ft_atol(split[2]);
}
