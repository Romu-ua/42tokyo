#include "main.h"

static void	ft_bsort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	calculation_threshold(t_node **stack)
{
	int		i;
	int		len;
	int		threshold;
	int		*indices;
	t_node	*tmp;

	len = list_len(stack);
	if (len == 0)
		return (-1);
	indices = (int *)malloc(sizeof(int) * len);
	if (!indices)
		return (-1);
	i = 0;
	tmp = *stack;
	while (i < len)
	{
		indices[i] = tmp->index;
		tmp = tmp->pnext;
		i++;
	}
	ft_bsort(indices, len);
	threshold = indices[len / 2];
	free(indices);
	return (threshold);
}

static int	start_node(t_node **a)
{
	int		cnt;
	t_node	*tmp;

	cnt = 0;
	tmp = *a;
	while (tmp->pnext != *a)
	{
		if (tmp->index == 0)
			break ;
		tmp = tmp->pnext;
		cnt++;
	}
	return (cnt);
}

static void	final_fix(t_node **a, t_ops **ops)
{
	int		len;
	int		cnt;

	len = list_len(a);
	cnt = start_node(a);
	if (cnt < len / 2)
	{
		while (cnt)
		{
			rotate_a(a, ops);
			cnt--;
		}
	}
	else
	{
		while (len - cnt)
		{
			reverse_rotate_a(a, ops);
			cnt++;
		}
	}
}

static int	get_elm_num(t_node **a)
{
	int		max;
	int		iwi;
	int		count;
	t_node	*tmp;

	max = -1;
	iwi = (*a)->pprev->index + 1;
	count = 0;
	tmp = *a;
	while (max - iwi != count)
	{
		//debug
		// printf("iwi is %d\n", iwi);
		// printf("max is %d\n", max);
		count++;
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->pnext;
	}
	return (count);
}

static void	b_init(t_node **b)
{
	(*b)->data = 0;
	(*b)->index = 0;
	(*b)->pnext = NULL;
	(*b)->pprev = NULL;
}

static void	sorted_elm_fix(t_node **a, t_ops **ops)
{

	// printf("(*a)->pprev->index is %d\n", (*a)->pprev->index);
	// int len = list_len(a);
	// printf("index\n");
	// for (int i = 0; i < len; i++) {
	// 	printf("%d\n", (*a)->index);
	// 	(*a) = (*a)->pnext;
	// }

	if ((*a)->pprev->index + 1 == (*a)->index)
	{
		// debug
		printf("found sorted elm\n");
		rotate_a(a, ops);
	}
}

void	operation(t_node **a, t_ops **ops)
{
	t_node	*b;
	int		threshold;
	int		elm_num;

	b = (t_node *)malloc(sizeof(t_node));
	if (!b)
		return ;
	b_init(&b);
	threshold = -1;
	while (!check_sorted_a(a))
	{
		threshold = calculation_threshold(a);
		threshold_push_b(a, &b, ops, threshold);
		while (1)
		{
			while (1)
			{
				if (list_len(&b) <= 3)
					break ;
				threshold = calculation_threshold(&b);
				threshold_push_a(a, &b, ops, threshold);
			}
			sort_fix(a, &b, ops);
			if (check_sorted_a(a))
				break;
			sorted_elm_fix(a, ops);
			if (check_sorted_a(a))
				break ;
			elm_num = get_elm_num(a);
			while (elm_num-- >= 0)
				push_b(a, &b, ops);
				
		}
	}
	free(b);
	final_fix(a, ops);
}
