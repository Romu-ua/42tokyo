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

t_ops	*create_newop(t_op op)
{
	t_ops	*new_op;

	new_op = (t_ops *)malloc(sizeof(t_ops));
	if (!new_op)
		return (NULL);
	new_op->op = op;
	new_op->pnext = NULL;
	new_op->pprev = NULL;
	return (new_op);
}

void	record_op(t_ops **ops, t_op op)
{
	t_ops	*new_op;
	t_ops	*last;

	new_op = create_newop(op);
	if (!new_op)
		return ;
	if (!*ops)
	{
		*ops = new_op;
		new_op->pnext = new_op;
		new_op->pprev = new_op;
	}
	else
	{
		last = (*ops)->pprev;
		new_op->pnext = *ops;
		new_op->pprev = last;
		last->pnext = new_op;
		(*ops)->pprev = new_op;
		*ops = new_op;
	}
}

void	print(t_op op)
{
	if (op == 0)
		write(1, "sa\n", 3);
	else if (op == 1)
		write(1, "sb\n", 3);
	else if (op == 2)
		write(1, "pa\n", 3);
	else if (op == 3)
		write(1, "pb\n", 3);
	else if (op == 4)
		write(1, "ra\n", 3);
	else if (op == 5)
		write(1, "rb\n", 3);
	else if (op == 6)
		write(1, "rra\n", 4);
	else if (op == 7)
		write(1, "rrb\n", 4);
}

void	print_ops(t_ops **ops)
{
	t_ops	*tmp;

	if (!ops || !*ops)
		return ;
	tmp = *ops;
	if ((*ops)->pprev == *ops)
	{
		print((*ops)->op);
		return ;
	}
	tmp = tmp->pprev;
	while (1)
	{
		print(tmp->op);
		if (tmp == *ops)
			break ;
		tmp = tmp->pprev;
	}
}
