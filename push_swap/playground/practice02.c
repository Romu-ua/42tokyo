// 循環双方向リストのソート
// indexを振るだけなので、バブルソートで良い

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	int index;
	struct node* pNextNode;
	struct node* pPrevNode;
} Node;

Node* createNode(int data)
{
	Node* newNode = (Node *)malloc(sizeof(Node));
	if (!newNode)
		return (NULL);
	newNode->data = data;
	newNode->index = -1;
	newNode->pNextNode = NULL;
	newNode->pPrevNode = NULL;
	return (newNode);
}

void insertAddHead(Node** head, int data)
{
	Node* newNode;

	newNode = createNode(data);
	if (!newNode)
		return ;
	if (!(*head))
	{
		*head = newNode;
		newNode->pNextNode = newNode;
		newNode->pPrevNode = newNode;
	}
	else
	{
		newNode->pNextNode = *head;
		newNode->pPrevNode = (*head)->pPrevNode;
		(*head)->pPrevNode->pNextNode = newNode;
		(*head)->pPrevNode = newNode;
		*head = newNode;
	}
}

int lengthList(Node** head)
{
	int len;
	Node* tmpNode;

	if (!*head)
		return (0);
	tmpNode = *head;
	len = 1;
	while (tmpNode->pNextNode != *head)
	{
		len++;
		tmpNode = tmpNode->pNextNode;
	}
	return (len);
}

void SortList(Node** head)
{
	int i, j, len, tmp;
	Node* currentNode;

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
			if (currentNode->data > currentNode->pNextNode->data)
			{
				tmp = currentNode->data;
				currentNode->data = currentNode->pNextNode->data;
				currentNode->pNextNode->data = tmp;
			}
			currentNode = currentNode->pNextNode;
			j++;
		}
		i++;
	}
}


void displayForward(Node** head)
{
	Node* tmpNode;
	if (!*head)
		return ;
	tmpNode = *head;
	while (tmpNode->pNextNode != *head)
	{
		printf("%d <-> ", tmpNode->data);
		tmpNode = tmpNode->pNextNode;
	}
	printf("%d <-> (Head)\n", tmpNode->data);
}

Node* searchNode(Node** head, int key)
{
	if (!*head)
		return (NULL);
	Node *tmpNode = *head;
	while (tmpNode->pNextNode != *head)
	{
		if (tmpNode->data == key)
			return (tmpNode);
		tmpNode = tmpNode->pNextNode;
	}
	if (tmpNode->data == key)
		return (tmpNode);
	return (NULL);
}

void AddIndex(Node** sorted)
{
	int index = 0;
	Node *tmpNode;

	if (!*sorted)
		return ;
	tmpNode = *sorted;
	while (tmpNode->pNextNode != *sorted)
	{
		tmpNode->index = index;
		index++;
		tmpNode = tmpNode->pNextNode;
	}
	tmpNode->index = lengthList(sorted) - 1;
}

void AddIndexHead(Node** head, Node** sorted)
{
	Node* searchedNode;
	Node* sorceNode;
	int i, len;

	sorceNode = *sorted;
	len = lengthList(head);
	i = 0;
	while (i < len)
	{
		searchedNode = searchNode(head, sorceNode->data);
		searchedNode->index = i;
		sorceNode = sorceNode->pNextNode;
		i++;
	}
}

int main()
{
	int sample[10] = {10, 9, 4, 5, 1, 2, 7, 8, 0, 3};
	Node *head = NULL, *copyhead = NULL;
	int i = 9;

	while (i >= 0)
	{
		insertAddHead(&head, sample[i]);
		insertAddHead(&copyhead, sample[i]);
		i--;
	}
	displayForward(&head);
	SortList(&copyhead);
	displayForward(&copyhead);

	AddIndex(&copyhead);
	i = 9;
	while (i >= 0)
	{
		printf("%d ", copyhead->index);
		copyhead = copyhead->pNextNode;
		i--;
	}

	printf("\n");
	AddIndexHead(&head, &copyhead);
	Node* tmpNode = head;
	i = 9;
	while (i >= 0)
	{
		printf("%d ", tmpNode->index);
		tmpNode = tmpNode->pNextNode;
		i--;
	}

	return (0);
}
