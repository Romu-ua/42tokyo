/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamamototaimu <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:14:05 by yamamototaimu     #+#    #+#             */
/*   Updated: 2025/02/24 14:14:06 by yamamototaimu    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

void	elm_3_a(t_node **a, t_ops **ops)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->pnext->index;
	third = (*a)->pprev->index;
	if (first > second && first < third)
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

void	elm_3_b(t_node **b, t_ops **ops)
{
	int	first;
	int	second;
	int	third;

	first = (*b)->index;
	second = (*b)->pnext->index;
	third = (*b)->pprev->index;
	if (first > second && first < third)
		reverse_rotate_b(b, ops);
	else if ((first > second && first > third) && second > third)
		return ;
	else if ((first > second && first > third) && second < third)
	{
		swap_b(b, ops);
		rotate_b(b, ops);
	}
	else if ((first < second && first < third) && second > third)
		rotate_b(b, ops);
	else if (first < second && first > third)
		swap_b(b, ops);
}

void	elm_4_5(t_node **a, t_node **b, t_ops **ops, int size)
{
	if (((*a)->index < (*a)->pnext->index)
		&& ((*a)->pnext->index < (*a)->pnext->pnext->index)
		&& ((*a)->pnext->pnext->index < (*a)->pprev->index)
		&& size == 4)
		return ;
	if (((*a)->index < (*a)->pnext->index)
		&& ((*a)->pnext->index < (*a)->pnext->pnext->index)
		&& ((*a)->pnext->pnext->index < (*a)->pprev->pprev->index)
		&& ((*a)->pprev->pprev->index < (*a)->pprev->index)
		&& size == 5)
		return ;
	half_push_b(a, b, ops);
	if ((*b)->pnext->index > (*b)->index)
		swap_b(b, ops);
	if (length_list(a) == 2)
	{
		if ((*a)->index > (*a)->pnext->index)
			swap_a(a, ops);
	}
	else
		elm_3_a(a, ops);
	push_a(a, b, ops);
	push_a(a, b, ops);
}

void	elm_6(t_node **a, t_node **b, t_ops **ops)
{
	t_node	*tmp;

	tmp = *a;
	while (tmp->pnext != *a)
	{
		if (tmp->index > tmp->pnext->index)
			break ;
		tmp = tmp->pnext;
	}
	if (tmp->pnext == *a)
		return ;
	half_push_b(a, b, ops);
	elm_3_a(a, ops);
	elm_3_b(b, ops);
	push_a(a, b, ops);
	push_a(a, b, ops);
	push_a(a, b, ops);
}

void	simple_sort(t_node **a, t_node **b, t_ops **ops, int size)
{
	if (size == 2)
	{
		if ((*a)->index > (*a)->pnext->index)
			swap_a(a, ops);
	}
	else if (size == 3)
		elm_3_a(a, ops);
	else if (size <= 5)
		elm_4_5(a, b, ops, size);
	else
		elm_6(a, b, ops);
}
