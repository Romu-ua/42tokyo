// 単方向リストの復習

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} Node;

// 新しいノードを作成。先頭に加える
void prepend(Node **head, int data)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = *head;
	*head = new_node;
}

void print_list(Node *head)
{
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
}

void free_list(Node *head)
{
	Node *current = head;
	while (current != NULL)
	{
		Node *next = current->next;
		free(current);
		current = next;
	}
}

int main()
{
	Node *head = NULL;

	prepend(&head, 3);
	prepend(&head, 2);
	prepend(&head, 1);

	printf("List: ");
	print_list(head);
	free_list(head);
	return (0);
}
