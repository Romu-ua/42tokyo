#include "main.h"

void	sort_three_a(t_node **a, t_ops **ops)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->pnext->index;
	third = (*a)->pprev->index;
	if (first < second && second < third)
		return ;
	else if (first > second && first < third)
		swap_a(a, ops);
	else if ((first > second && first > third) && second > third)
	{
		swap_a(a, ops);
		reverse_rotate_a(a, ops);
	}
	else if ((first > second && first > third) && second < third)
		rotate_a(a, ops);
	else if ((first < second && first < third) && second > third)
	{
		swap_a(a, ops);
		rotate_a(a, ops);
	}
	else if (first < second && first > third)
		reverse_rotate_a(a, ops);
}

void	sort_three_b(t_node **b, t_ops **ops)
{
	int	first;
	int	second;
	int	third;

	first = (*b)->index;
	second = (*b)->pnext->index;
	third = (*b)->pprev->index;

	if (first < second && second < third)
	{
		swap_b(b, ops);
		reverse_rotate_b(b, ops);
	}
	else if (first < third && third < second)
		rotate_b(b, ops);
	else if (first > third && third > second) 
		swap_b(b, ops);
	else if (first > second && second < third)
		reverse_rotate_b(b, ops);
	else if (first > third && third < second)
	{
		swap_b(b, ops);
		rotate_b(b, ops);
	}
}
