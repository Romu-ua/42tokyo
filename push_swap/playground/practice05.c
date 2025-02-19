// チャンクごとにBにpush
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

// -------------------------------------------

int	lengthList(Node **stack)
{
	Node	*tmpNode;
	int		len;

	if (!*stack)
		return (0);
	tmpNode = *stack;
	len = 1;
	while (tmpNode->pNextNode != *stack)
	{
		len++;
		tmpNode = tmpNode->pNextNode;
	}
	return (len);
}

void push_chunk(Node **A, Node **B, int start, int end)
{
	int		len = lengthList(A);
	int		i = 0;

	while (i < len)
	{
		if (!*A)
			break;
		// printf("/%d-%d/ \n", start, end);
		if ((*A)->index >= start && (*A)-> index <= end)
		{
			push(A, B);
		}
		else
			rotate(A);
		i++;
	}
}

void pushAtoB(Node** A, Node** B)
{
	int	len, chunk_num, chunk_size;
	int	start, end, i;

	len = lengthList(A);
	if (len > 500)
		chunk_num = len / 50;
	else if (len > 100)
		chunk_num = 11;
	else
		chunk_num = 5;

	if (!*A)
		return ;
	i = 0;
	chunk_size = len / chunk_num;
	while (i < chunk_num)
	{
		start = i * chunk_size;
		end = (i == chunk_num - 1) ? (len - 1) : (start + chunk_size - 1);
		push_chunk(A, B, start, end);
		i++;
	}
}

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

void AddIndex(Node** head, Node** sorted)
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

int main()
{
	int sample[10] = {10, 9, 4, 5, 1, 2, 7, 8, 0, 3};
	Node *A = NULL, *B = NULL, *sorted = NULL;
	int i = 9;

	while (i >= 0)
	{
		insertAddHead(&A, sample[i]);
		insertAddHead(&sorted, sample[i]);
		i--;
	}
	SortList(&sorted);
	printf("sorted ");
	displayForward(&sorted);

	// AddIndexは機能している
	AddIndex(&A, &sorted);
	// Node* tmpNode = A;
	// for (int i = 0; i < lengthList(&A); i++) {
	// 	printf("%d <-> ", tmpNode->index);
	// 	tmpNode = tmpNode->pNextNode;
	// }
	// printf("(HEAD)\n");

	pushAtoB(&A, &B);

	printf("A ");
	displayForward(&A);
	printf("\n");
	printf("B ");
	displayForward(&B);
	return (0);
}
