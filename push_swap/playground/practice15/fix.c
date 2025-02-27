/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:50:22 by hyamamot          #+#    #+#             */
/*   Updated: 2025/02/19 15:50:24 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	start_node(t_node **A)
{
	int		cnt;
	t_node	*tmp;

	cnt = 0;
	tmp = *A;
	while (tmp->pnext != *A)
	{
		if (tmp->index == 0)
			break ;
		tmp = tmp->pnext;
		cnt++;
	}
	return (cnt);
}

void	final_fix(t_node **A, t_ops **ops)
{
	int		len;
	int		cnt;

	len = length_list(A);
	cnt = start_node(A);
	if (cnt < len / 2)
	{
		while (cnt)
		{
			rotate_a(A, ops);
			cnt--;
		}
	}
	else
	{
		while (len - cnt - 1)
		{
			reverse_rotate_a(A, ops);
			cnt++;
		}
	}
}

void	fix(t_node **A, t_node **B, t_ops **ops)
{
	int	len;

	len = length_list(B);
	while (len)
	{
		push_a(B, A, ops);
		rotate_a(A, ops);
		len--;
	}
}
