#include "Cupid.h"

void	ft_free(void)
{
	t_gc	**head;
	t_gc	*curr;
	t_gc	*temp;

	head = NULL;
	head = ft_gc();
	curr = *head;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free(temp->ptr);
		temp->ptr = NULL;
		free(temp);
		temp = NULL;
	}
	*head = NULL;
}
