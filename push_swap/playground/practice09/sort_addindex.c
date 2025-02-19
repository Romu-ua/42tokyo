#include "main.h"

void AddIndex(t_node** head, t_node** sorted)
{
	t_node* searchedNode;
	t_node* sorceNode;
	int i, len;

	sorceNode = *sorted;
	len = lengthList(head);
	i = 0;
	while (i < len)
	{
		searchedNode = searchNode(head, sorceNode->data);
		searchedNode->index = i;
		sorceNode = sorceNode->pnextnode;
		i++;
	}
}

void SortList(t_node** head)
{
	int i, j, len, tmp;
	t_node *currentNode;

	if (!*head)
		return ;
	i = 0;
	len = lengthList(head);
	while (i < len - 1)
	{
		j = 0;
		currentNode = *head;
		while (j < len - i - 1)
		{
			if (currentNode->data > currentNode->pnextnode->data)
			{
				tmp = currentNode->data;
				currentNode->data = currentNode->pnextnode->data;
				currentNode->pnextnode->data = tmp;
			}
			currentNode = currentNode->pnextnode;
			j++;
		}
		i++;
	}
}
