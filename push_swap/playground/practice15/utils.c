/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:15:42 by hyamamot          #+#    #+#             */
/*   Updated: 2025/02/19 16:15:43 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_node	*create_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->index = -1;
	new_node->pnext = NULL;
	new_node->pprev = NULL;
	return (new_node);
}

void	insert_add_head(t_node **head, int data)
{
	t_node	*new_node;

	new_node = create_node(data);
	if (!new_node)
		return ;
	if (!(*head))
	{
		*head = new_node;
		new_node->pnext = new_node;
		new_node->pprev = new_node;
	}
	else
	{
		new_node->pnext = *head;
		new_node->pprev = (*head)->pprev;
		(*head)->pprev->pnext = new_node;
		(*head)->pprev = new_node;
		*head = new_node;
	}
}

t_node	*search_node(t_node **head, int key)
{
	t_node	*tmp_node;

	if (!*head)
		return (NULL);
	tmp_node = *head;
	while (tmp_node->pnext != *head)
	{
		if (tmp_node->data == key)
			return (tmp_node);
		tmp_node = tmp_node->pnext;
	}
	if (tmp_node->data == key)
		return (tmp_node);
	return (NULL);
}
