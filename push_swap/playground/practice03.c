// practice02.cでindexを振ることはできたので、
// チャンクを分けてbにpush,aにpushする段階でソートする

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


// チャンクの分け方はとりあえず半分にしておく (工夫の余地あり)
void PushAtoB(Node** A, Node** B)
{
	int threshold;

	threshold = lengthList(A) / 2 - 1;
	Node *currentNode = *A;
	while (1)
	{
		Node *nextNode = currentNode->pNextNode;
		if (currentNode->index <= threshold)
		{
			insertAddHead(B, currentNode->data);
			currentNode->pPrevNode->pNextNode = currentNode->pNextNode;
			currentNode->pNextNode->pPrevNode = currentNode->pPrevNode;

			if (currentNode == *A)
			{
				if (currentNode->pNextNode == currentNode)
				{
					*A = NULL;
					free(currentNode);
					break;
				}
				else
					*A = nextNode;
			}

			free(currentNode);
		}
		if (*A == NULL)
			break;
		currentNode = nextNode;
		if (currentNode == *A)
			break;
	}

	// 残りは単にpushする
	while (1)
	{
		Node *nextNode = currentNode->pNextNode;
		insertAddHead(B, currentNode->data);
		currentNode = nextNode;
		if (currentNode == *A)
			break;
	}
	*A = NULL;
}

int	insertPosition(Node **A, int index)
{
	Node *currentNode = *A;
	int len = lengthList(A);
	int pos = 1;

	if (currentNode == NULL || len == 1)
		return (1);
	while (1);
	{
		Node *nextNode = currentNode->pNextNode;

		if (index < currentNode->index)
			return (pos);
		currentNode = nextNode;
		pos++;
		if (currentNode == *A)
			return (pos);
	}
}

void rotateA(Node** A, int pos)
{
	int len = lengthList(A);

	if (len / 2 < pos)
	{
		while (pos)
		{
			ra(A);
		}
	}
	else
	{
		while (len - pos)
		{
			rra(A);
		}
	}
}

void PushBtoA(Node **A, Node **B)
{
	int pos;
	Node *currentNode = *B;

	while (1)
	{
		// 挿入位置を発見
		pos = insertPosition(A, currentNode->index);

		// rotate aで回転してpush
		// rotateAでraかrraかを判断
		// posは1-based index
		rotateA(A, pos);

		pa(A, B);
	}
}


int main()
{
	int sample[10] = {10, 9, 4, 5, 1, 2, 7, 8, 0, 3};
	Node *A = NULL, *copy = NULL;
	Node *B = NULL;
	int i = 9;

	while (i >= 0)
	{
		insertAddHead(&A, sample[i]);
		insertAddHead(&copy, sample[i]);
		i--;
	}
	SortList(&copy);
	AddIndex(&A, &copy);
	PushAtoB(&A, &B);

	displayForward(&A);
	displayForward(&B);

	PushBtoA(&A, &B);


	return (0);
}
