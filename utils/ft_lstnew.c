#include "Cupid.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*t;

	t = (t_list *)ft_malloc(sizeof(t_list));
	if (!t)
		return (NULL);
	t->content = content;
	t->next = NULL;
	return (t);
}
