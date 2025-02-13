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

void SortAddIndex(Node **head)
{

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

int main()
{
	int sample[10] = {10, 9, 4, 5, 1, 2, 7, 8, 0, 3};
	Node* head = NULL;
	int i = 9;

	while (i >= 0)
	{
		insertAddHead(&head, sample[i]);
		i--;
	}
	displayForward(&head);
	return (0);
}
