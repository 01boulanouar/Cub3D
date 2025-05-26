#include "Cupid.h"

void	*ft_malloc(size_t size)
{
	t_gc	**head;
	t_gc	*new_node;
	void	*ptr;

	head = ft_gc();
	ptr = malloc(size);
	if (!ptr)
		ft_exit(EXIT_FAILURE);
	new_node = malloc(sizeof(t_gc));
	if (!new_node)
		ft_exit(EXIT_FAILURE);
	new_node->ptr = ptr;
	new_node->next = *head;
	*head = new_node;
	return (ptr);
}
