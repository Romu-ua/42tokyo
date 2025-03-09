#include "main.h"

static void	sub_sort_fix(t_node **a, t_node **b, t_ops **ops)
{
	printf("sub_sort\n");
	push_a(b, a, ops);
	rotate_a(a, ops);
}

void	sort_fix(t_node **a, t_node **b, t_ops **ops)
{
	int	i;

	i = 0;
	if (list_len(b) == 3)
	{
		sort_three_b(b, ops);
		while (i++ < 3)
			sub_sort_fix(a, b, ops);
	}
	else if (list_len(b) == 2)
	{
		// debug
		printf("b len is 2\n");
		if ((*b)->index > (*b)->pnext->index)
			swap_b(b, ops);
		while (i++ < 2)
			sub_sort_fix(a, b, ops);
	}
	else
		sub_sort_fix(a, b, ops);
}
