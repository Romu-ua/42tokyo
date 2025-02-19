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
	{
		// printf("case 1 only_sb\n");
		record_op(ops, sb);
		return ;
	}
	else if (sb_rrb(B))
	{
		// printf("case 2 sa_rra\n");
		record_op(ops, sb);
		record_op(ops, rrb);
		return ;
	}
	else if (only_rb(B))
	{
		// printf("case 3 only_ra\n");
		record_op(ops, rb);
		return ;
	}
	else if (sb_rb(B))
	{
		// printf("case 4 sa_ra\n");
		record_op(ops, sb);
		record_op(ops, rb);
		return ;
	}
	else if (only_rrb(B))
	{
		// printf("case 5 only_rra");
		record_op(ops, rrb);
		return ;
	}
	return ;
}

void	sort(t_node **B, t_ops **ops)
{
	int	len;

	len = lengthList(B);
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

void	fix(t_node **A, t_node **B, t_ops **ops)
{
	int	len;

	len = lengthList(B);
	while (len)
	{
		push_a(B, A, ops);
		rotateA(A, ops);
		len--;
	}
}

// すでに昇順にソートされていると機能しない
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

	// printf("min : %d\n", min);
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
	t_node *start;
	t_node *tmp;

	tmp = *A;
	// start　nodeを見つける
	while (tmp->pnextnode != *A)
	{
		if (tmp->index == 0)
		{
			start = tmp;
			break;
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
			if (lengthList(B) <= 3)
				break;
			half_push_A(B, A, ops);
			displayForward(A);
			displayForward(B);
		}
		sort(B, ops);
		fix(A, B, ops);
		
		// printf("after fix A : ");
		displayForward(A);
		// printf("Before displayForward: A = %p, A->pnextnode = %p\n", (void*)*A, (void*)(*A ? (*A)->pnextnode : NULL));
		// displayForward(A);
		// printf("After displayForward: A = %p, A->pnextnode = %p\n", (void*)*A, (void*)(*A ? (*A)->pnextnode : NULL));


		if (check_sorted(A))
		{
			printf("finish sort!!\n");
			break;
		}
		elm_num = get_elm_num(A);
		printf("elm_num is %d\n", elm_num);
		while (elm_num > 0)
		{
			push_b(A, B, ops);
			// printf("pa\n");
			elm_num--;
		}
		// displayForward(A);
		// displayForward(B);
	}

}
