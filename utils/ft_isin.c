#include "Cupid.h"

int	ft_isin(const char c, const char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}
