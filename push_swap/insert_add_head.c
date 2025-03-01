#include "main.h"

t_node	*create_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->index = -1;
	new_node->pnext = new_node;
	new_node->pprev = new_node;
	return (new_node);
}

void	insert_add_head(t_node **head, int data)
{
	t_node	*new_node;
	t_node	*last_node;

	new_node = create_node(data);
	if (!new_node)
		return ;
	if (!(*head))
	{
		*head = new_node;
		return ;
	}
	last_node = (*head)->pprev;
	new_node->pnext = *head;
	new_node->pprev = last_node;
	last_node->pnext = new_node;
	(*head)->pprev = new_node;
	*head = new_node;
	
}