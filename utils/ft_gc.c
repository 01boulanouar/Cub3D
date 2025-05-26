#include "Cupid.h"

t_gc	**ft_gc(void)
{
	static t_gc	*head;

	return (&head);
}
