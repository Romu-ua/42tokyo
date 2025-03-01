// 双方向リストの復習

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* pPrevNode;
	struct node* pNextNode;
} Node;

/*
	双方向リストで行える操作一覧
	1.ノードの作成
	2.リストの初期化
	3.先頭にノードを追加
	4.末尾にノードを追加
	5.指定位置にノードを追加
	6.先頭のノードを削除
	7.末尾のノードを削除
	8.指定位置のノードを削除
	9.リストの表示 (前方向)
	10.リストの表示 (後方向)
	11.リストの全削除
*/

typedef struct {
	Node* head;
	Node* tail;
} DoublyLinkedList;

// 1.ノードの作成
Node* createNode(int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (!newNode)
		return (NULL);
	newNode->data = data;
	newNode->pNextNode = NULL;
	newNode->pPrevNode = NULL;
	return (newNode);
}

// 2.リストの初期化
void initList(DoublyLinkedList* list)
{
	list->head = NULL;
	list->tail = NULL;
}

// 3.先頭にノードを追加
void insertAtHead(DoublyLinkedList* list, int data)
{
	Node* newNode = createNode(data);
	if (!newNode)
		return;
	if (list->head == NULL)
		list->head = list->tail = newNode;
	else
	{
		newNode->pNextNode = list->head;
		list->head->pPrevNode = newNode;
		list->head = newNode;
	}
}

// 4.末尾にノードを追加
void insertAtTail(DoublyLinkedList* list, int data)
{
	Node* newNode = createNode(data);
	if (!newNode)
		return ;
	if (list->head == NULL)
		list->head = list->tail = NULL;
	else
	{
		list->tail->pNextNode = newNode;
		newNode->pPrevNode = list->tail;
		list->tail = newNode;
	}
}

// 5.指定位置にノードを追加 (1-based index)
void insertAtPosition(DoublyLinkedList* list, int data, int position)
{
	if (position <= 1)
	{
		insertAtHead(list, data);
		return ;
	}

	Node* newNode = createNode(data);
	if (!newNode)
		return ;

	Node* tmpNode = list->head;
	int i = 1;
	while (i < position - 1 && tmpNode != NULL)
	{
		tmpNode = tmpNode->pNextNode;
		i++;
	}

	// positionがリストの範囲外の時とtailを指している時,最後尾につける
	if (tmpNode == NULL || tmpNode->pNextNode == NULL)
	{
		insertAtTail(list, data);
		return ;
	}

	newNode->pNextNode = tmpNode->pNextNode;
	newNode->pPrevNode = tmpNode;
	tmpNode->pNextNode = newNode;
	tmpNode->pNextNode->pPrevNode = newNode;
}

// 6.先頭のノードを削除
void deleteAtHead(DoublyLinkedList* list)
{
	if (!list->head)
		return ;

	Node* tmpNode = list->head;
	list->head = list->head->pNextNode;

	// 一個の時はlistが指しているtailをNULLにする必要がある
	if (list->head == NULL)
		list->tail = NULL;
	else
		list->head->pPrevNode = NULL;
	free(tmpNode);
}

// 7.末尾のノードを削除
void deleteAtTail(DoublyLinkedList* list)
{
	if (!list->tail)
		return ;
	Node* tmpNode = list->tail;
	list->tail = list->tail->pPrevNode;

	if (list->tail == NULL)
		list->head = NULL;
	else
		list->tail->pNextNode = NULL;
	free(tmpNode);
}

// 8.指定位置のノードを削除(1-based index)
void deleteAtPosition(DoublyLinkedList* list, int position)
{
	if (!list->head || position <= 1)
	{
		deleteAtHead(list);
		return ;
	}

	Node *tmpNode = list->head;

	int i = 1;
	// tmpは削除するノードを指している
	while (i < position && tmpNode != NULL)
	{
		tmpNode = tmpNode->pNextNode;
		i++;
	}
	if (tmpNode == NULL)
		return ;

	// 一番最後尾を指している時
	if (tmpNode->pNextNode == NULL)
		list->tail = tmpNode->pPrevNode;
	else
		tmpNode->pNextNode->pPrevNode = tmpNode->pPrevNode;

	// 先頭を指している時はエラー処理しているからこの場合は書かなくてよい
	tmpNode->pPrevNode->pNextNode = tmpNode->pNextNode;

	free(tmpNode);
}

// 9.前方向にリストを表示
void displayForward(DoublyLinkedList* list)
{
	if (!list->head)
		return ;
	Node* tmpNode = list->head;

	while (tmpNode)
	{
		printf("%d <->", tmpNode->data);
		tmpNode = tmpNode->pNextNode;
	}
	printf("NULL\n");
}

// 10.後ろ方向にリストを表示
void displayBackward(DoublyLinkedList* list)
{
	if (!list->tail)
		return ;

	Node* tmpNode = list->tail;
	while (tmpNode)
	{
		printf("%d <-> ", tmpNode->data);
		tmpNode = tmpNode->pPrevNode;
	}
	printf("NULL\n");
}

// 11.リスト内のノードを探索
Node* searchNode(DoublyLinkedList* list, int key)
{
	Node* tmpNode = list->head;
	while(!tmpNode)
	{
		if (tmpNode->data == key)
			return (tmpNode);
		tmpNode = tmpNode->pNextNode;
	}
	return (NULL);
}

// 12.リストを完全に削除
void clearList(DoublyLinkedList* list)
{
	Node* tmpNode = list->head;

	while(!tmpNode)
	{
		Node* nextNode = tmpNode->pNextNode;
		free(tmpNode);
		tmpNode = nextNode;
	}
	list->head = list->tail = NULL;
}

int main()
{
	DoublyLinkedList list;
	initList(&list);

	insertAtHead(&list, 10);
	insertAtHead(&list, 20);
	insertAtHead(&list, 30);

	printf("Forward:");
	displayForward(&list);

	printf("Backward:");
	displayBackward(&list);

	deleteAtHead(&list);
	deleteAtTail(&list);
	deleteAtPosition(&list, 2);

	printf("After Deletion: \n");
	printf("Forward:");
	displayForward(&list);

	Node* found = searchNode(&list, 10);
	if (found)
		printf("Found node with data : %d\n", found->data);
	else
		printf("Node not found");

	clearList(&list);
	return (0);
}

/*
構造体の実体に値を代入するのが
構造体の実体のポインタを使って値を代入するのが ->
-> は (*ptr)member シンタックスシュガーであり
やっていることは,ポインタ実体化させて.で値を代入しているだけ
*/
