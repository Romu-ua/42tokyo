/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_addindex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:19:40 by hyamamot          #+#    #+#             */
/*   Updated: 2025/02/17 18:19:41 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	add_index(t_node **head, t_node **sorted)
{
	t_node	*searchednode;
	t_node	*sourcenode;
	int		i;
	int		len;

	sourcenode = *sorted;
	len = length_list(head);
	i = 0;
	while (i < len)
	{
		searchednode = search_node(head, sourcenode->data);
		searchednode->index = i;
		sourcenode = sourcenode->pnext;
		i++;
	}
}

void	sort_list(t_node **head)
{
	int		i;
	int		j;
	int		len;
	int		tmp;
	t_node	*currentnode;

	if (!*head)
		return ;
	i = 0;
	len = length_list(head);
	while (i++ < len)
	{
		j = 0;
		currentnode = *head;
		while (j++ < len - i)
		{
			if (currentnode->data > currentnode->pnext->data)
			{
				tmp = currentnode->data;
				currentnode->data = currentnode->pnext->data;
				currentnode->pnext->data = tmp;
			}
			currentnode = currentnode->pnext;
		}
	}
}
