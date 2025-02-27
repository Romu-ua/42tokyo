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
	if ((*src)->pnext == (*src))
		*src = NULL;
	else
	{
		(*src)->pnext->pprev = (*src)->pprev;
		(*src)->pprev->pnext = (*src)->pnext;
		*src = (*src)->pnext;
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
		topsrc->pnext = topsrc;
		topsrc->pprev = topsrc;
	}
	else
	{
		topsrc->pnext = *dest;
		topsrc->pprev = (*dest)->pprev;
		(*dest)->pprev->pnext = topsrc;
		(*dest)->pprev = topsrc;
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
		topsrc->pnext = topsrc;
		topsrc->pprev = topsrc;
	}
	else
	{
		topsrc->pnext = *dest;
		topsrc->pprev = (*dest)->pprev;
		(*dest)->pprev->pnext = topsrc;
		(*dest)->pprev = topsrc;
		*dest = topsrc;
	}
	if (ops)
		record_op(ops, pb);
}
