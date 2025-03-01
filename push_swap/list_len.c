#include "main.h"

int	list_len(t_node **a)
{
	t_node	*tmp_node;
	int		len;

	if (!a || !*a)
		return (0);
	tmp_node = *a;
	len = 1;
	while (*a != tmp_node->pnext)
	{
		tmp_node = tmp_node->pnext;
		len++;
	}
	return (len);
}