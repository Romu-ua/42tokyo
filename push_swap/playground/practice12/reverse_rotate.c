/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:04:39 by hyamamot          #+#    #+#             */
/*   Updated: 2025/02/15 12:04:40 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "main.h"

void	reverse_rotateA(t_node** stack, t_ops **ops)
{
	if (!*stack || (*stack)->pnextnode == *stack)
		return ;
	*stack = (*stack)->pprevnode;
	if (ops)
		record_op(ops, rra);
}

void	reverse_rotateB(t_node** stack, t_ops **ops)
{
	if (!*stack || (*stack)->pnextnode == *stack)
		return ;
	*stack = (*stack)->pprevnode;
	if (ops)
		record_op(ops, rrb);
}
