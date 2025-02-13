// 循環リストについて学習

/*
1.ノードの作成
2.先頭にノードを追加
3.末尾にノードを追加
4.指定位置にノードを追加
5.先頭のノードを削除
6.末尾のノードを削除
7.指定位置のノードを削除
8.リストの前方表示
9.リストの後方表示
10.リストの探索
11.リストの回転
12.リストの逆回転
13.リストの全削除
14.リストの長さを数える
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* pNextNode;
	struct node* pPrevNode;
} Node;

// 0.リストの長さを数える
int lengthlist(Node **head)
{
	if (!*head)
		return (0);
	int len = 1;
	Node *currentNode = *head;
	while (currentNode->pNextNode != *head)
	{
		len++;
		currentNode = currentNode->pNextNode;
	}
	return (len);
}

// 1.ノードの初期化
Node* createNode(int data)
{
	Node* newNode = (Node *)malloc(sizeof(Node));
	if (!newNode)
		return (NULL);
	newNode->data = data;
	newNode->pNextNode = newNode;
	newNode->pPrevNode = newNode;
	return (newNode);
}


// 2.先頭にノードを追加
void insertAtHead(Node **head, int data)
{
	Node* newNode = createNode(data);
	if (!newNode)
		return ;
	if(!(*head))
	{
		*head = newNode;
		(*head)->pNextNode = newNode;
		(*head)->pPrevNode = newNode;
	}
	else
	{
		Node* tail = (*head)->pPrevNode;

		newNode->pNextNode = *head;
		newNode->pPrevNode = tail;
		(*head)->pPrevNode = newNode;
		tail->pNextNode = newNode;
		*head = newNode;
	}
}

// 3.末尾にノードを追加
void insertAtTail(Node **head, int data)
{
	Node *newNode = createNode(data);
	if (!newNode)
		return ;
	if (!(*head))
	{
		*head = newNode;
		newNode->pNextNode = newNode;
		newNode->pPrevNode = newNode;
		// ここの処理がinsertAtHeadと同じなので、以下でも可
		// insertAtHead(head, data);
	}
	else
	{
		Node *tail = (*head)->pPrevNode;

		newNode->pNextNode = *head;
		newNode->pPrevNode = tail;
		(*head)->pPrevNode = newNode;
		tail->pNextNode = newNode;
	}
}

// 4.指定位置にノードを追加 (1-based index)
void insertAtPosition(Node **head, int data, int position)
{
	Node *newNode = createNode(data);
	if (!newNode)
		return ;
	if (!(*head) || position == 1)
	{
		insertAtHead(head, data);
		return ;
	}

	Node *tmpNode = *head;
	int i = 1;
	while (i < position - 1 && tmpNode->pNextNode != *head)
	{
		tmpNode = tmpNode->pNextNode;
		i++;
	}
	newNode->pNextNode = tmpNode;
	newNode->pPrevNode = tmpNode->pPrevNode;
	tmpNode->pPrevNode->pNextNode = newNode;
	tmpNode->pPrevNode = newNode;
}

// 5.先頭のノードを削除
void deleteAtHead(Node **head)
{
	if (!*head)
		return ;
	Node *tmpNode = *head;
	// ノードが一つだけの時
	if ((*head)->pNextNode == tmpNode)
		*head = NULL;
	else
	{
		Node *tailNode = tmpNode->pPrevNode;

		*head = (*head)->pNextNode;
		(*head)->pPrevNode = tailNode;
		tailNode->pNextNode = *head;
	}
	free(tmpNode);
}

// 6.末尾のノードを削除
void deleteAtTail(Node **head)
{
	if (!(*head))
		return ;
	Node *tmpNode = (*head)->pPrevNode;

	if (tmpNode->pPrevNode == tmpNode)
		*head = NULL;
	else
	{
		tmpNode->pPrevNode->pNextNode = *head;
		(*head)->pPrevNode = tmpNode->pPrevNode;
	}
	free(tmpNode);
}

// 7.指定位置のノードを削除
void deleteAtPosition(Node **head, int position)
{
	if (!(*head) || position == 1)
	{
		deleteAtHead(head);
		return ;
	}
	if (position < 1)
		return ;
	int len = lengthlist(head);
	if (len < position)
		return ;

	Node *tmpNode = *head;
	int	i = 1;
	while (tmpNode->pNextNode != *head && i < position)
	{
		tmpNode = tmpNode->pNextNode;
		i++;
	}
	// 一つしかない場合
	if (!tmpNode->pNextNode)
		*head = NULL;
	else
	{
		tmpNode->pPrevNode->pNextNode = tmpNode->pNextNode;
		tmpNode->pNextNode->pPrevNode = tmpNode->pPrevNode;
	}
	free(tmpNode);
}

// 8.リストの前方表示
void displayForward(Node **head)
{
	if (!*head)
		return ;
	Node *tmpNode = *head;
	while (tmpNode->pNextNode != *head)
	{
		printf("%d <-> ", tmpNode->data);
		tmpNode = tmpNode->pNextNode;
	}
	printf("%d <-> (Head)\n", tmpNode->data);
}

// 9.リストの後方表示
void displayBackward(Node** head)
{
	if (!*head)
		return ;
	Node *tmpNode = (*head)->pPrevNode;
	while(tmpNode != *head)
	{
		printf("%d <-> ", tmpNode->data);
		tmpNode = tmpNode->pPrevNode;
	}
	printf("%d <-> (Tail)\n", tmpNode->data);
}
// 10.リストの探索
Node *searchNode(Node **head, int key)
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

// 11.リストの回転
void rotateForward(Node **head)
{
	if (!*head || (*head)->pNextNode == *head)
		return ;
	*head = (*head)->pNextNode;
}
// 12.リストの逆回転
void rotateBackward(Node **head)
{
	if (!*head || (*head)->pNextNode == *head)
		return ;
	*head = (*head)->pPrevNode;
}
// 13.リストの全削除
void clearList(Node **head)
{
	if (!*head)
		return ;
	Node *tmpNode = *head;
	while (tmpNode->pNextNode != *head)
	{
		Node *nextNode = tmpNode->pNextNode;
		free(tmpNode);
		tmpNode = nextNode;
	}
	free(tmpNode);
	*head = NULL;
}

// メイン関数
int main() {
    Node* head = NULL;

    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);

    printf("Original List:\n");
    displayForward(&head);

    rotateForward(&head);
    printf("After One Forward Rotation:\n");
    displayForward(&head);

    rotateBackward(&head);
    printf("After One Backward Rotation:\n");
    displayForward(&head);

    clearList(&head);
    return 0;
}
