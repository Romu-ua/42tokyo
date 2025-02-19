/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:04:57 by hyamamot          #+#    #+#             */
/*   Updated: 2025/02/15 12:04:58 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	swap_a(t_node** stack, t_ops *ops)
{
	int	tmpdata;
	int	tmpindex;

	if (!*stack || (*stack)->pnextnode == *stack)
		return ;
	tmpdata = (*stack)->data;
	tmpindex = (*stack)->index;
	(*stack)->data = (*stack)->pnextnode->data;
	(*stack)->index = (*stack)->pnextnode->index;
	(*stack)->pnextnode->data = tmpdata;
	(*stack)->pnextnode->index = tmpindex;

	if (ops)
		record_op(ops, sa);
}

void	swap_b(t_node** stack, t_ops *ops)
{
	int	tmpdata;
	int	tmpindex;

	if (!*stack || (*stack)->pnextnode == *stack)
		return ;
	tmpdata = (*stack)->data;
	tmpindex = (*stack)->index;
	(*stack)->data = (*stack)->pnextnode->data;
	(*stack)->index = (*stack)->pnextnode->index;
	(*stack)->pnextnode->data = tmpdata;
	(*stack)->pnextnode->index = tmpindex;
	if (ops)
		record_op(ops, sb);
}
