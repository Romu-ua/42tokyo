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

#include "main.h"

void	reverse_rotate_a(t_node **stack, t_ops **ops)
{
	if (!*stack || (*stack)->pnext == *stack)
		return ;
	*stack = (*stack)->pprev;
	if (ops)
		record_op(ops, rra);
}

void	reverse_rotate_b(t_node **stack, t_ops **ops)
{
	if (!*stack || (*stack)->pnext == *stack)
		return ;
	*stack = (*stack)->pprev;
	if (ops)
		record_op(ops, rrb);
}
