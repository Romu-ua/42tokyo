/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:04:49 by hyamamot          #+#    #+#             */
/*   Updated: 2025/02/15 12:04:50 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	rotate_a(t_node **stack, t_ops **ops)
{
	if (!*stack || (*stack)->pprev == *stack)
		return ;
	*stack = (*stack)->pnext;
	if (ops)
		record_op(ops, ra);
}

void	rotate_b(t_node **stack, t_ops **ops)
{
	if (!*stack || (*stack)->pprev == *stack)
		return ;
	*stack = (*stack)->pnext;
	if (ops)
		record_op(ops, rb);
}
