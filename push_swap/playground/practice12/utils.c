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
	new_node->pnextnode = NULL;
	new_node->pprevnode = NULL;
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
		new_node->pnextnode = new_node;
		new_node->pprevnode = new_node;
	}
	else
	{
		new_node->pnextnode = *head;
		new_node->pprevnode = (*head)->pprevnode;
		(*head)->pprevnode->pnextnode = new_node;
		(*head)->pprevnode = new_node;
		*head = new_node;
	}
}

t_node	*search_node(t_node **head, int key)
{
	t_node	*tmp_node;

	if (!*head)
		return (NULL);
	tmp_node = *head;
	while (tmp_node->pnextnode != *head)
	{
		if (tmp_node->data == key)
			return (tmp_node);
		tmp_node = tmp_node->pnextnode;
	}
	if (tmp_node->data == key)
		return (tmp_node);
	return (NULL);
}
