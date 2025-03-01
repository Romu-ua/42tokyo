#include "main.h"

void	subaddidx(t_node **a, int *arr, int len)
{
	t_node	*tmp_node;
	int		i;

	i = 0;
	while (i < len)
	{
		tmp_node = *a;
		while (1)
		{
			if (arr[i] == tmp_node->data)
			{
				tmp_node->index = i;
				break ;
			}
			if (*a == tmp_node->pnext)
				break ;
			tmp_node = tmp_node->pnext;
		}
		i++;
	}
}

void	addidx(t_node **a, char **argv)
{
	int	*arr;
	int	len;
	int	i;

	len = list_len(a);
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return ;
	i = 0;
	while (i < len)
	{
		arr[i] = ft_atol(argv[i + 1]);
		i++;
	}
	ft_sort(arr, len);
	subaddidx(a, arr, len);
}

