#include "main.h"

void	sort_four_a(t_node **a, t_ops **ops)
{
	t_node	**b;

	b = (t_node **)malloc(sizeof(t_node));
	threshold_push_b(a, b, ops, 0);
	sort_three_a(a, ops);
	push_a(b, a, ops);
}

void	sort_five_a(t_node **a, t_ops **ops)
{
	t_node	**b;

	b = (t_node **)malloc(sizeof(t_node));;
	threshold_push_b(a, b, ops, 1);
	sort_three_a(a, ops);
	if ((*b)->index < (*b)->pnext->index)
		swap_b(b, ops);
	push_a(b, a, ops);
	push_a(b, a, ops);
}

void	sort_six_a(t_node **a, t_ops **ops)
{
	t_node	**b;

	b = (t_node **)malloc(sizeof(t_node));;
	threshold_push_b(a, b, ops, 2);
	sort_three_a(a, ops);
	sort_three_b(b, ops);
	push_a(b, a, ops);
	push_a(b, a, ops);
	push_a(b, a, ops);
}

void	simple_sort(t_node **a, t_ops **ops, int size)
{
	if (size == 2)
	{
		if ((*a)->index > (*a)->pnext->index)
			swap_a(a, ops);
	}
	else if (size == 3)
		sort_three_a(a, ops);
	else if (size == 4)
		sort_four_a(a, ops);
	else if (size == 5)
		sort_five_a(a, ops);
	else
		sort_six_a(a, ops);
}
