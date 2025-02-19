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

void	rotateA(t_node** stack, t_ops **ops)
{
	if (!*stack || (*stack)->pprevnode == *stack)
		return ;
	*stack = (*stack)->pnextnode;
	if (ops)
		record_op(ops, ra);
}
void	rotateB(t_node** stack, t_ops **ops)
{
	if (!*stack || (*stack)->pprevnode == *stack)
		return ;
	*stack = (*stack)->pnextnode;
	if (ops)
		record_op(ops, rb);
}
