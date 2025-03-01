#include "main.h"

int	check_sorted_a(t_node **a)
{
	t_node	*tmp;

	if (!a || !*a)
		return (0);
	tmp = *a;
	while (1)
	{
		if (tmp->index > tmp->pnext->index)
			return (1);
		if (*a == tmp->pnext)
			break ;
		tmp = tmp->pnext;
	}
	return (0);
}