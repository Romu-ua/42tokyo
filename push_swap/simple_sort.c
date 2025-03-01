#include "main.h"

// TODO push_bをするときに、どちらにrotateしたらよいのかを判断させる。
void	small_elm_push_b(t_node **a, t_node **b, t_ops **ops)
{
	int	i;
	int	len;

	len = list_len(a);
	i = 0;
	while (i < len)
	{
		if ((*a)->index <= 2)
			push_b(a, b, ops);
		else
			rotate_a(a, ops);
		i++;
	}
	sort_three_b(b, ops);
}

void	sort_four_to_six(t_node **a, t_ops **ops)
{
	t_node	*b;
	int		len;
	int		i;

	b = NULL;
	printf("in sort_four_to_six\n");
	if (!check_sorted_a(a))
		return ;
	printf("pass through\n");
	small_elm_push_b(a, &b, ops);
	len = list_len(a);
	if (len == 2)
	{
		if ((*a)->index > (*a)->pnext->index)
			swap_a(a, ops);
	}
	else if (len == 3)
		sort_three_a(a, ops);
	i = 0;
	while (i < 3)
	{
		push_a(&b, a, ops);
		i++;
	}
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
	else 
		sort_four_to_six(a, ops);
}