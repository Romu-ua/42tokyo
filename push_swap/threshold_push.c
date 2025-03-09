#include "main.h"

static int	search_node_a(t_node **a, int threshold)
{
	int		len;
	int		pos;
	t_node	*tmp;

	tmp = *a;
	len = list_len(a);
	pos = 0;
	while (pos < len)
	{
		if (tmp->index <= threshold)
			return (pos);
		tmp = tmp->pnext;
		pos++;
	}
	return (-1);
}

static int	search_node_b(t_node **b, int threshold)
{
	int		len;
	int		pos;
	t_node	*tmp;

	tmp = *b;
	len = list_len(b);
	// printf("%d\n", len);
	pos = 0;
	while (pos < len)
	{
		if (tmp->index >= threshold)
			return (pos);
		tmp = tmp->pnext;
		pos++;
	}
	return (-1);
}

void	threshold_push_b(t_node **a, t_node **b, t_ops **ops, int threshold)
{
	int	pos;
	int	len;

	while (search_node_a(a, threshold) != -1)
	{
		len = list_len(a);
		pos = search_node_a(a, threshold);
		if (pos < len / 2)
		{
			while (pos > 0)
			{
				rotate_a(a, ops);
				pos--;
			}
		}
		else
		{
			while (pos < len)
			{
				reverse_rotate_a(a, ops);
				pos++;
			}
		}
		push_b(a, b, ops);
	}
}

void	threshold_push_a(t_node **a, t_node **b, t_ops **ops, int threshold)
{
	int	pos;
	int	len;

	while (search_node_b(b, threshold) != -1)
	{
		len = list_len(b);
		pos = search_node_b(b, threshold);
		if (pos < len / 2)
		{
			while (pos > 0)
			{
				rotate_b(b, ops);
				pos--;
			}
		}
		else
		{
			while (pos < len)
			{
				reverse_rotate_b(b, ops);
				pos++;
			}
		}
		push_a(b, a, ops);
	}
}
