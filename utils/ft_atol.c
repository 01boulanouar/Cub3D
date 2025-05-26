#include "Cupid.h"

unsigned long long	ft_atol(const char *str)
{
	long long	num;
	int			signe;

	num = 0;
	signe = 1;
	while (ft_isspace(*str))
		str++;
	if (!ft_strcmp(str, "-9223372036854775808"))
		return (LONG_MAX + 1ul);
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			signe *= -1;
	}
	while (ft_isdigit(*str))
	{
		if (num > num * 10 + (*str - '0'))
			return (LONG_MAX + 1ul);
		num = num * 10 + (*str - '0');
		str++;
	}
	return ((long long)num * signe);
}
