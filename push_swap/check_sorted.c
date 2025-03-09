#include "main.h"

static t_node	*start_node(t_node **a)
{
	t_node	*tmp;

	tmp = *a;
	while (tmp->pnext != *a)
	{
		if (tmp->index == 0)
			break ;
		tmp = tmp->pnext;
	}
	return (tmp);
}

int	check_sorted_a(t_node **a)
{
	t_node	*tmp;
	t_node	*start;

	if (!a || !*a)
		return (0);
	start = start_node(a);
	tmp = start;
	while (1)
	{
		if (tmp->index > tmp->pnext->index)
			return (1);
		if (start == tmp->pnext)
			break ;
		tmp = tmp->pnext;
	}
	return (0);
}
