/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 23:43:54 by hyamamot          #+#    #+#             */
/*   Updated: 2025/02/17 23:43:55 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	only_sb(t_node **B)
{
	swap_b(B, NULL);
	if ((*B)->index < (*B)->pnext->index
		&& (*B)->pnext->index < (*B)->pprev->index)
		return (1);
	swap_b(B, NULL);
	return (0);
}

int	sb_rrb(t_node **B)
{
	swap_b(B, NULL);
	reverse_rotate_b(B, NULL);
	if ((*B)->index < (*B)->pnext->index
		&& (*B)->pnext->index < (*B)->pprev->index)
		return (1);
	rotate_b(B, NULL);
	swap_b(B, NULL);
	return (0);
}

int	only_rb(t_node **B)
{
	rotate_b(B, NULL);
	if ((*B)->index < (*B)->pnext->index
		&& (*B)->pnext->index < (*B)->pprev->index)
		return (1);
	reverse_rotate_b(B, NULL);
	return (0);
}

int	sb_rb(t_node **B)
{
	swap_b(B, NULL);
	rotate_b(B, NULL);
	if ((*B)->index < (*B)->pnext->index
		&& (*B)->pnext->index < (*B)->pprev->index)
		return (1);
	reverse_rotate_b(B, NULL);
	swap_b(B, NULL);
	return (0);
}

int	only_rrb(t_node **B)
{
	reverse_rotate_b(B, NULL);
	if ((*B)->index < (*B)->pnext->index
		&& (*B)->pnext->index < (*B)->pprev->index)
		return (1);
	rotate_b(B, NULL);
	return (0);
}
