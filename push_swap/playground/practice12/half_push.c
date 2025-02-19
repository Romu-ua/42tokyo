/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   half_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:56:17 by hyamamot          #+#    #+#             */
/*   Updated: 2025/02/17 18:56:18 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int	calculation_threshold(t_node **stack)
{
	int		i;
	int		len;
	int		threshold;
	int		*indices;
	t_node	*tmp;

	len = length_list(stack);
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
		tmp = tmp->pnextnode;
		i++;
	}
	qsort(indices, len, sizeof(int), compare);
	threshold = indices[len / 2];
	free(indices);
	return (threshold);
}

void	half_push_b(t_node **A, t_node **B, t_ops **ops)
{
	int		len;
	int		i;
	int		threshold;

	threshold = calculation_threshold(A);
	if (threshold == -1)
		return ;
	len = length_list(A);
	i = 0;
	while (i < len)
	{
		if ((*A)->index < threshold)
		{
			push_b(A, B, ops);
			i++;
			continue ;
		}
		i++;
		rotate_a(A, ops);
	}
}

void	half_push_a(t_node **B, t_node **A, t_ops **ops)
{
	int		len;
	int		i;
	int		threshold;

	len = length_list(B);
	threshold = calculation_threshold(B);
	if (threshold == -1)
		return ;
	i = 0;
	while (i < len)
	{
		if ((*B)->index > threshold)
		{
			push_a(B, A, ops);
			i++;
			continue ;
		}
		i++;
		rotate_b(B, ops);
	}
}
