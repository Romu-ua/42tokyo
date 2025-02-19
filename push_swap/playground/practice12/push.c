/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:04:06 by hyamamot          #+#    #+#             */
/*   Updated: 2025/02/15 12:04:12 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	remove_list(t_node **src)
{
	if ((*src)->pnextnode == (*src))
		*src = NULL;
	else
	{
		(*src)->pnextnode->pprevnode = (*src)->pprevnode;
		(*src)->pprevnode->pnextnode = (*src)->pnextnode;
		*src = (*src)->pnextnode;
	}
}

void	push_a(t_node **src, t_node **dest, t_ops **ops)
{
	t_node	*topsrc;

	if (!*src)
		return ;
	topsrc = *src;
	remove_list(src);
	if (!*dest)
	{
		*dest = topsrc;
		topsrc->pnextnode = topsrc;
		topsrc->pprevnode = topsrc;
	}
	else
	{
		topsrc->pnextnode = *dest;
		topsrc->pprevnode = (*dest)->pprevnode;
		(*dest)->pprevnode->pnextnode = topsrc;
		(*dest)->pprevnode = topsrc;
		*dest = topsrc;
	}
	if (ops)
		record_op(ops, pa);
}

void	push_b(t_node **src, t_node **dest, t_ops **ops)
{
	t_node	*topsrc;

	if (!*src)
		return ;
	topsrc = *src;
	remove_list(src);
	if (!*dest)
	{
		*dest = topsrc;
		topsrc->pnextnode = topsrc;
		topsrc->pprevnode = topsrc;
	}
	else
	{
		topsrc->pnextnode = *dest;
		topsrc->pprevnode = (*dest)->pprevnode;
		(*dest)->pprevnode->pnextnode = topsrc;
		(*dest)->pprevnode = topsrc;
		*dest = topsrc;
	}
	if (ops)
		record_op(ops, pb);
}
