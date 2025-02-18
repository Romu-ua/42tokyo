/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:08:21 by hyamamot          #+#    #+#             */
/*   Updated: 2025/02/18 17:08:22 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	record_op(t_ops *ops, t_op op)
{
	t_op_list	*new_node;
	t_op_list	*tail;

	if (!ops)
		return ;
	new_node = (t_op_list *)malloc(sizeof(t_op_list));
	if (!new_node)
		return ;
	new_node->op = op;
	if (!ops->op_list)
	{
		ops->op_list = new_node;
		new_node->pprev = new_node;
		new_node->pnext = new_node;
	}
	else
	{
		tail = ops->op_list->pprev;

		// 順番合ってる？
		tail->pnext = new_node;
		ops->op_list->pprev = new_node;
		new_node->pnext = ops->op_list;
		new_node->pprev = tail;
	}
	ops->size++;
	// printf("Recorded op at index : %d\n", ops->size);
}

void	print_ops(t_ops *ops)
{
	t_op_list	*cur;
	int			i;

	if (!ops || !ops->op_list || ops->size == 0)
		return ;
	cur = ops->op_list;
	while (i < ops->size)
	{
		if (cur->op == 0)
			printf("sa\n");
		else if (cur->op == 1)
			printf("sb\n");
		else if (cur->op == 2)
			printf("pa\n");
		else if (cur->op == 3)
			printf("pb\n");
		else if (cur->op == 4)
			printf("ra\n");
		else if (cur->op == 5)
			printf("rb\n");
		else if (cur->op == 6)
			printf("rra\n");
		else if (cur->op == 7)
			printf("rrb\n");
		cur = cur->pnext;
		i++;
	}
}
