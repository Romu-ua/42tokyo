#include "main.h"

int	lengthList(t_node **stack)
{
	t_node	*tmpNode;
	int		len;

	if (!stack || !*stack)
		return (0);
	tmpNode = *stack;
	len = 1;
	while (tmpNode->pnextnode != *stack)
	{
		len++;
		tmpNode = tmpNode->pnextnode;
	}
	return (len);
}

t_node* createNode(int data)
{
	t_node* newNode = (t_node *)malloc(sizeof(t_node));
	if (!newNode)
		return (NULL);
	newNode->data = data;
	newNode->index = -1;
	newNode->pnextnode = NULL;
	newNode->pprevnode = NULL;
	return (newNode);
}

void insertAddHead(t_node** head, int data)
{
	t_node* newNode;

	newNode = createNode(data);
	if (!newNode)
		return ;
	if (!(*head))
	{
		*head = newNode;
		newNode->pnextnode = newNode;
		newNode->pprevnode = newNode;
	}
	else
	{
		newNode->pnextnode = *head;
		newNode->pprevnode = (*head)->pprevnode;
		(*head)->pprevnode->pnextnode = newNode;
		(*head)->pprevnode = newNode;
		*head = newNode;
	}
}

t_node* searchNode(t_node** head, int key)
{
	if (!*head)
		return (NULL);
	t_node *tmpNode = *head;
	while (tmpNode->pnextnode != *head)
	{
		if (tmpNode->data == key)
			return (tmpNode);
		tmpNode = tmpNode->pnextnode;
	}
	if (tmpNode->data == key)
		return (tmpNode);
	return (NULL);
}
