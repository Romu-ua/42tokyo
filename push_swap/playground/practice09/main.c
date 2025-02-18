/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:04:20 by hyamamot          #+#    #+#             */
/*   Updated: 2025/02/15 12:04:23 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "main.h"

int	lengthList(t_node **stack)
{
	t_node	*tmpNode;
	int		len;

	if (!*stack)
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

void push_chunk(t_node **A, t_node **B, int start, int end, t_ops *ops)
{
	int		len = lengthList(A);
	int		i = 0;

	while (i < len)
	{
		if (!*A)
			break;
		if ((*A)->index >= start && (*A)-> index <= end)
		{
			push_b(A, B, ops);
		}
		else
			rotateA(A, ops);
		i++;
	}
}

void pushAtoB(t_node** A, t_node** B, t_ops *ops)
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
		push_chunk(A, B, start, end, ops);
		i++;
	}
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

int	insertPosition(t_node** A, int index)
{
	t_node *tmpNode, *nextNode;
	int	pos;

	pos = 1;
	if (!*A || (*A)->pnextnode == *A)
		return (pos);
	tmpNode = (*A);
	while (1)
	{
		nextNode = tmpNode->pnextnode;
		if (tmpNode->index > index)
			break;
		pos++;
		tmpNode = nextNode;
		if (tmpNode == *A)
			break;
	}
	return (pos);
}

void rotateA_with_pos(t_node** A, int pos, t_ops *ops)
{
	int len, i;

	len = lengthList(A);
	i = 1;
	if (pos <= len / 2)
	{
		while (i < pos)
		{
			i++;
			rotateA(A, ops);
		}
	}
	else
	{
		while (i < len - pos)
		{
			reverse_rotateA(A, ops);
			i++;
		}
	}
}

void subsort(t_node** A, t_ops *ops)
{
	if ((*A)->index > (*A)->pnextnode->index)
		swap_a(A, ops);
}

void pushBtoA(t_node **A, t_node **B, t_ops *ops)
{
	int	pos;

	if (!*B)
		return ;
	while (*B)
	{
		pos = insertPosition(A, (*B)->index);
		rotateA_with_pos(A, pos, ops);
		push_a(B, A, ops);
		if (lengthList(A) == 2)
			subsort(A, ops);
	}
}

int searchMinNode(t_node **A)
{
	int pos;

	if (!*A)
		return (0);
	t_node *tmpNode = *A;
	pos = 1;
	while (1)
	{
		t_node *nextNode = tmpNode->pnextnode;
		if (tmpNode->index == 0)
			return (pos);
		pos++;
		tmpNode = nextNode;
		if (tmpNode == *A)
			break;
	}
	return (-1);
}

void fix(t_node** A, t_ops *ops)
{
	int len, minindexpos, i;

	len = lengthList(A);
	minindexpos = searchMinNode(A);
	i = 0;
	if (minindexpos < len / 2)
	{
		while (i < minindexpos)
		{
			rotateA(A, ops);
			i++;
		}
	}
	else
	{
		while (i < len - minindexpos + 1)
		{
			reverse_rotateA(A, ops);
			i++;
		}
	}

}

void print_ops(t_ops *ops)
{
	for (int i = 0; i < ops->size; i++)
	{
		switch (ops->op_list[i])
		{
			case sa: printf("sa\n"); break;
			case sb: printf("sb\n"); break;
			case pa: printf("pa\n"); break;
			case pb: printf("pb\n"); break;
			case ra: printf("ra\n"); break;
			case rb: printf("rb\n"); break;
			case rra: printf("rra\n"); break;
			case rrb: printf("rrb\n"); break;
		}
	}
}

void displayForward(t_node** head)
{
	t_node* tmpNode;
	if (!*head)
		return ;
	tmpNode = *head;
	while (tmpNode->pnextnode != *head)
	{
		printf("%d <-> ", tmpNode->data);
		tmpNode = tmpNode->pnextnode;
	}
	printf("%d <-> (Head)\n", tmpNode->data);
}

void	deleteList(t_node **stack)
{
	t_node *tmp;
	int		len;
	int		i;

	len = lengthList(stack);
	if (stack == NULL)
		return ;
	i = 0;
	while (i < len)
	{
		tmp = *stack;
		*stack = tmp->pnextnode;
		free(tmp);
		i++;
	}
	*stack = NULL;
}

int main(int argc, char **argv)
{
	int *sample;
	int	i;
	t_node *A = NULL, *B = NULL, *sorted = NULL;
	t_ops ops = {NULL, 0, 0};

	// printf("%d\n", argc);
	sample = (int *)malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (i < argc - 1)
	{
		sample[i] = atoi(argv[i+1]);
		i++;
	}
	i--;
	while (i >= 0)
	{
		insertAddHead(&A, sample[i]);
		insertAddHead(&sorted, sample[i]);
		i--;
	}
	SortList(&sorted);
	printf("sorted: ");
	displayForward(&sorted);
	AddIndex(&A, &sorted);
	i = 0;
	printf("index: ");
	while (i < argc - 1)
	{
		printf("%d <-> ", A->index);
		A = A->pnextnode;
		i++;
	}
	printf("(Head)\n");

	pushAtoB(&A, &B, &ops);
	pushBtoA(&A, &B, &ops);

	fix(&A, &ops);
	displayForward(&A);
	print_ops(&ops);
	free(ops.op_list);
	deleteList(&A);
	deleteList(&B);
	return (0);
}
