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

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void	half_push_B(t_node **A, t_node **B, t_ops **ops)
{
	int		len;
	int		i;
	int		threshold;
	int		*indices;
	t_node	*tmp;

	len = lengthList(A);
	indices = (int *)malloc(sizeof(int) * len);
	if (!indices)
		return ;
	i = 0;
	tmp = *A;
	while (i < len)
	{
		indices[i] = tmp->index;
		tmp = tmp->pnextnode;
		i++;
	}
	qsort(indices, len, sizeof(int), compare);
	threshold = indices[len / 2];
	free(indices);
	i = 0;
	while (i < len)
	{
		if ((*A)->index < threshold)
		{
			push_b(A, B, ops);
			i++;
			continue;
		}
		i++;
		rotateA(A, ops);
	}
}

void	half_push_A(t_node **B, t_node **A, t_ops **ops)
{
	int		len;
	int		i;
	int		threshold;
	int		*indices;
	t_node	*tmp;


	len = lengthList(B);
	indices = (int *)malloc(sizeof(int) * len);
	if (!indices)
		return ;
	i = 0;
	tmp = *B;
	while (i < len)
	{
		indices[i] = tmp->index;
		tmp = tmp->pnextnode;
		i++;
	}
	qsort(indices, len, sizeof(int), compare);

	threshold = indices[len / 2];
	free(indices);
	i = 0;
	while (i < len)
	{
		if ((*B)->index > threshold)
		{

			push_a(B, A, ops);
			i++;
			continue;
		}
		i++;
		rotateB(B, ops);
	}
}
