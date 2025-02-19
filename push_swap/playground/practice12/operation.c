/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:05:44 by hyamamot          #+#    #+#             */
/*   Updated: 2025/02/17 21:05:45 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	sort_n3(t_node **B, t_ops **ops)
{
	if (only_sb(B))
		record_op(ops, sb);
	else if (sb_rrb(B))
	{
		record_op(ops, sb);
		record_op(ops, rrb);
	}
	else if (only_rb(B))
		record_op(ops, rb);
	else if (sb_rb(B))
	{
		record_op(ops, sb);
		record_op(ops, rb);
	}
	else if (only_rrb(B))
		record_op(ops, rrb);
	return ;
}

void	sort(t_node **B, t_ops **ops)
{
	int	len;

	len = length_list(B);
	if (len == 1)
		return ;
	else if (len == 2)
	{
		if ((*B)->index > (*B)->pnextnode->index)
			swap_b(B, ops);
	}
	else
		sort_n3(B, ops);
}

int	get_elm_num(t_node **A)
{
	int		max;
	int		min;
	int		count;
	t_node	*tmp;

	if (!A)
		return (-1);
	max = -1;
	min = (*A)->pprevnode->index + 1;
	count = 0;
	tmp = *A;
	while (max - min + 1 != count)
	{
		count++;
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->pnextnode;
	}
	return (count);
}

int	check_sorted(t_node **A)
{
	t_node	*start;
	t_node	*tmp;

	tmp = *A;
	start = NULL;
	while (tmp->pnextnode != *A)
	{
		if (tmp->index == 0)
		{
			start = tmp;
			break ;
		}
		tmp = tmp->pnextnode;
	}
	if (!start)
		return (0);
	tmp = start;
	while (start->pnextnode != tmp)
	{
		if (start->index != start->pnextnode->index - 1)
			return (0);
		start = start->pnextnode;
	}
	return (1);
}

void	operation(t_node **A, t_node **B, t_ops **ops)
{
	int	elm_num;

	while (1)
	{
		while (1)
		{
			if (length_list(B) <= 3)
				break ;
			half_push_a(B, A, ops);
		}
		sort(B, ops);
		fix(A, B, ops);
		if (check_sorted(A))
			break ;
		elm_num = get_elm_num(A);
		if (elm_num == 0)
			break ;
		while (elm_num > 0)
		{
			push_b(A, B, ops);
			elm_num--;
		}
	}
}
