#include "Cupid.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	srclen;
	size_t	i;

	if (!s)
		return (NULL);
	srclen = ft_strlen(s);
	if (start >= srclen)
		return (ft_strdup(""));
	if (len > srclen - start)
		len = srclen - start;
	dst = (char *)ft_malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		dst[i] = s[start];
		start++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
