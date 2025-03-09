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
	int		min;
	int		count;
	t_node	*tmp;

	if (!a)
		return (-1);
	max = -1;
	min = (*a)->pprev->index + 1;
	count = 0;
	tmp = *a;
	while (max - min + 1 != count)
	{
		count++;
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->pnext;
	}
	return (count);
}

void	operation(t_node **a, t_ops **ops)
{
	t_node	*b;
	int		threshold;
	int		elm_num;
	int		i;

	b = (t_node *)malloc(sizeof(t_node));
	threshold = -1;
	while (check_sorted_a(a))
	{
		threshold = calculation_threshold(a);
		// debug
		printf("threshold %d\n", threshold);
		threshold_push_b(a, &b, ops, threshold);
		// debug
		printf("-----------\n");
		t_node	*tmp;
		tmp = (*a);
		int len = list_len(a);
		for (int i = 0; i < len; i++) {
			printf("%d\n", tmp->data);
			tmp = tmp->pnext;
		}
		printf("-----------\n");
		tmp = b;
		len = list_len(&b);
		for (int i = 0; i < len; i++) {
			printf("%d\n", tmp->data);
			tmp = tmp->pnext;
		}
		printf("-----------\n");
		while (1)
		{

			while (1)
			{
				if (list_len(&b) <= 3)
					break ;
				threshold = calculation_threshold(&b);
				// debug
				printf("b threshold is %d\n", threshold);
				threshold_push_a(a, &b, ops, threshold);
				// debug
				printf("-----------\n");
				t_node	*tmp;
				tmp = (*a);
				int len = list_len(a);
				for (int i = 0; i < len; i++) {
					printf("%d\n", tmp->data);
					tmp = tmp->pnext;
				}
				printf("-----------\n");
				tmp = b;
				len = list_len(&b);
				for (int i = 0; i < len; i++) {
					printf("%d\n", tmp->data);
					tmp = tmp->pnext;
				}
				printf("-----------\n");
			}
			sort_fix(a, &b, ops);
			// debug
			printf("-----------\n");
			t_node	*tmp;
			tmp = (*a);
			int len = list_len(a);
			for (int i = 0; i < len; i++) {
				printf("%d\n", tmp->data);
				tmp = tmp->pnext;
			}
			printf("-----------\n");

			if (check_sorted_a(a)) {
				printf("after sort_fix check_sorted_a\n");
				break;
			}
			elm_num = get_elm_num(a);
			// debug
			printf("elm_num is %d\n", elm_num);
			i = -1;
			while (++i <= elm_num)
				push_b(a, &b, ops);
		}
	}
	free(b);
	final_fix(a, ops);
}
