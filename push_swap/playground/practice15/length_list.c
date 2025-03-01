/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:23:33 by hyamamot          #+#    #+#             */
/*   Updated: 2025/02/19 16:23:34 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	length_list(t_node **stack)
{
	t_node	*tmp_node;
	int		len;

	if (!stack || !*stack)
		return (0);
	tmp_node = *stack;
	len = 1;
	while (tmp_node->pnext != *stack)
	{
		len++;
		tmp_node = tmp_node->pnext;
	}
	return (len);
}

int	op_length_list(t_ops **ops)
{
	t_ops	*tmp;
	int		len;

	if (!ops || !*ops)
		return (0);
	tmp = *ops;
	len = 1;
	while (tmp->pnext != *ops)
	{
		len++;
		tmp = tmp->pnext;
	}
	return (len);
}
