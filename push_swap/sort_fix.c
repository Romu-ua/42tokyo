#include "main.h"

static void	sub_sort_fix(t_node **a, t_node **b, t_ops **ops)
{
	// printf("sub_sort\n");
	push_a(b, a, ops);
	rotate_a(a, ops);
}

static void	sub_three_sort(t_node **b, t_ops **ops)
{
	int	first;
	int	second;
	int	third;

	first = (*b)->index;
	second = (*b)->pnext->index;
	third = (*b)->pprev->index;
	if (first < second && second < third)
		return ;
	else if (first > second && first < third)
		swap_a(b, ops);
	else if ((first > second && first > third) && second > third)
	{
		swap_a(b, ops);
		reverse_rotate_a(b, ops);
	}
	else if ((first > second && first > third) && second < third)
		rotate_a(b, ops);
	else if ((first < second && first < third) && second > third)
	{
		swap_a(b, ops);
		rotate_a(b, ops);
	}
	else if (first < second && first > third)
		reverse_rotate_a(b, ops);
}

void	sort_fix(t_node **a, t_node **b, t_ops **ops)
{
	int	i;

	i = 0;
	if (list_len(b) == 3)
	{
		// debug
		// t_node *tmp;

		// tmp = (*b);
		// for (int i = 0; i < 3; i++) {
		// 	printf("%d\n", tmp->index);
		// 	tmp = tmp->pnext;
		// }

		// printf("sort_fix b len 3\n");
		sub_three_sort(b, ops);
		// debug
		// tmp = (*b);
		// for (int i = 0; i < 3; i++) {
		// 	printf("%d\n", tmp->index);
		// 	tmp = tmp->pnext;
		// }

		while (i++ < 3)
			sub_sort_fix(a, b, ops);
	}
	else if (list_len(b) == 2)
	{
		// debug
		// printf("b len is 2\n");
		if ((*b)->index > (*b)->pnext->index)
			swap_b(b, ops);
		while (i++ < 2)
			sub_sort_fix(a, b, ops);
	}
	else
		sub_sort_fix(a, b, ops);
}
