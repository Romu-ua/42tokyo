// 許可されている操作を実装

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int	data;
	int index;
	struct node* pNextNode;
	struct node* pPrevNode;
} Node;

void	swap(Node** stack)
{
	int	tmpdata;
	int	tmpindex;

	if (!*stack || (*stack)->pNextNode == *stack)
		return ;
	tmpdata = (*stack)->data;
	tmpindex = (*stack)->index;
	(*stack)->data = (*stack)->pNextNode->data;
	(*stack)->index = (*stack)->pNextNode->index;
	(*stack)->pNextNode->data = tmpdata;
	(*stack)->pNextNode->index = tmpindex;
}

// srcからdestにpush
void	push(Node** src, Node** dest)
{
	Node *topSrc, *destHead, *destTail;

	if (!*src)
		return ;
	// srcのtopを取り除く
	topSrc = *src;
	if ((*src)->pNextNode == (*src))
		*src = NULL;
	else
	{
		(*src)->pNextNode->pPrevNode = (*src)->pPrevNode;
		(*src)->pPrevNode->pNextNode = (*src)->pNextNode;
		*src = (*src)->pNextNode;
	}
	// destにpush
	if (!*dest)
	{
		*dest = topSrc;
		topSrc->pNextNode = topSrc;
		topSrc->pPrevNode = topSrc;
	}
	else
	{
		destHead = *dest;
		destTail = (*dest)->pPrevNode;
		topSrc->pNextNode = destHead;
		topSrc->pPrevNode = destTail;
		destHead->pPrevNode = topSrc;
		destTail->pNextNode = topSrc;

		*dest = topSrc;
	}
}

void	rotate(Node** stack)
{
	if (!*stack || (*stack)->pPrevNode == *stack)
		return ;
	*stack = (*stack)->pNextNode;
}

void	reverse_rotate(Node** stack)
{
	if (!*stack || (*stack)->pNextNode == *stack)
		return ;
	*stack = (*stack)->pPrevNode;
}


// ------------------------------------------------
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
	Node *A = NULL, *B = NULL;
	int i = 9;

	while (i >= 0)
	{
		insertAddHead(&A, sample[i]);
		i--;
	}

	displayForward(&A);
	swap(&A);
	displayForward(&A);
	insertAddHead(&B, 100);
	push(&B, &A);
	displayForward(&A);
	rotate(&A);
	displayForward(&A);
	reverse_rotate(&A);
	displayForward(&A);

	return (0);
}
