// 行なった操作を別の配列に保存する

// 回転方向を決めて、raかrraをしてからpushBtoAをする
// チャンクごとにBにpush
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int	data;
	int index;
	struct node* pNextNode;
	struct node* pPrevNode;
} Node;

typedef enum e_op {
	sa,
	sb,
	pa,
	pb,
	ra,
	rb,
	rra,
	rrb
} t_op;

// 列挙型(enum)の構造体
typedef struct s_ops {
	t_op *op_list;
	int size;
	int capacity;
} t_ops;

// -------------------------
void *my_realloc(void *ptr, size_t new_size)
{
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(new_size));
	void *new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	memcpy(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
}

// 配列が満タンなら拡張
void ensure_capacity(t_ops *ops)
{
	if (ops->size >= ops->capacity)
	{
		int new_cap = (ops->capacity == 0) ? 42 : ops->capacity * 2;
		t_op *new_list = my_realloc(ops->op_list, new_cap * sizeof(t_op));
		if (!new_list)
			exit(1);

		ops->op_list = new_list;
		ops->capacity = new_cap;
	}
}

void record_op(t_ops *ops, t_op op)
{
	ensure_capacity(ops);
	ops->op_list[ops->size] = op;
	ops->size++;
}


void	swapA(Node** stack, t_ops *ops)
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

	record_op(ops, sa);
}

void	swapB(Node** stack, t_ops *ops)
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

	record_op(ops, sb);
}

// srcからdestにpush
void	pushA(Node** src, Node** dest, t_ops *ops)
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
	record_op(ops, pa);
}

void	pushB(Node** src, Node** dest, t_ops *ops)
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
	record_op(ops, pb);
}

void	rotateA(Node** stack, t_ops *ops)
{
	if (!*stack || (*stack)->pPrevNode == *stack)
		return ;
	*stack = (*stack)->pNextNode;
	record_op(ops, ra);
}
void	rotateB(Node** stack, t_ops *ops)
{
	if (!*stack || (*stack)->pPrevNode == *stack)
		return ;
	*stack = (*stack)->pNextNode;
	record_op(ops, rb);
}

void	reverse_rotateA(Node** stack, t_ops *ops)
{
	if (!*stack || (*stack)->pNextNode == *stack)
		return ;
	*stack = (*stack)->pPrevNode;
	record_op(ops, rra);
}

void	reverse_rotateB(Node** stack, t_ops *ops)
{
	if (!*stack || (*stack)->pNextNode == *stack)
		return ;
	*stack = (*stack)->pPrevNode;
	record_op(ops, rrb);
}

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

void push_chunk(Node **A, Node **B, int start, int end, t_ops *ops)
{
	int		len = lengthList(A);
	int		i = 0;

	while (i < len)
	{
		if (!*A)
			break;
		if ((*A)->index >= start && (*A)-> index <= end)
		{
			pushB(A, B, ops);
		}
		else
			rotateA(A, ops);
		i++;
	}
}

void pushAtoB(Node** A, Node** B, t_ops *ops)
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

// --------------------------

int	insertPosition(Node** A, int index)
{
	Node *tmpNode, *nextNode;
	int	pos;

	pos = 1;
	if (!*A || (*A)->pNextNode == *A)
		return (pos);
	tmpNode = (*A);
	while (1)
	{
		nextNode = tmpNode->pNextNode;
		if (tmpNode->index > index)
			break;
		pos++;
		tmpNode = nextNode;
		if (tmpNode == *A)
			break;
	}
	return (pos);
}



void rotateA_with_pos(Node** A, int pos, t_ops *ops)
{
	int len, i;

	len = lengthList(A);
	i = 1;
	// printf("pos is %d\n", pos);
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

void subsort(Node** A, t_ops *ops)
{
	if ((*A)->index > (*A)->pNextNode->index)
		swapA(A, ops);
}

void pushBtoA(Node** A, Node** B, t_ops *ops)
{
	int	pos;

	if (!*B)
		return ;
	// 挿入位置の発見
	// 1-based index
	while (*B)
	{
		pos = insertPosition(A, (*B)->index);

		// 回転
		rotateA_with_pos(A, pos, ops);

		// push
		pushA(B, A, ops);

		if (lengthList(A) == 2)
			subsort(A, ops);
		// displayForward(A);
		// printf("\n");
	}
}

int searchMinNode(Node** A)
{
	int pos;

	if (!*A)
		return (0);
	Node *tmpNode = *A;
	pos = 1;
	while (1)
	{
		Node *nextNode = tmpNode->pNextNode;
		if (tmpNode->index == 0)
			return (pos);
		pos++;
		tmpNode = nextNode;
		if (tmpNode == *A)
			break;
	}
	return (-1);
}

void fix(Node** A, t_ops *ops)
{
	int len, minindexpos, i;

	len = lengthList(A);
	minindexpos = searchMinNode(A);
	// printf("min pos is %d\n", minindexpos);
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

int main()
{

	int sample[10] = {10, 9, 4, 5, 1, 2, 7, 8, 0, 3};
	// int sample[500] = {711, 545, 325, 494, 492, 314, 909, 919, 494, 3, 547, 975, 235, 640, 986, 85, 734, 241, 745, 468, 671, 432, 123, 589, 902, 710, 312, 457, 821, 679, 501, 903, 146, 852, 347, 276, 584, 999, 208, 619, 485, 734, 231, 804, 125, 372, 687, 957, 418, 764, 592, 831, 204, 627, 518, 972, 456, 682, 307, 945, 219, 891, 536, 428, 755, 643, 990, 133, 581, 726, 874, 263, 490, 732, 109, 350, 867, 741, 289, 930, 674, 823, 562, 913, 205, 487, 788, 902, 643, 376, 418, 591, 987, 204, 650, 832, 718, 291, 406, 573, 895, 764, 238, 140, 621, 476, 950, 802, 314, 795, 430, 669, 711, 542, 831, 647, 215, 383, 957, 120, 341, 468, 257, 890, 673, 901, 589, 423, 560, 748, 201, 372, 985, 726, 549, 832, 312, 765, 419, 583, 640, 997, 504, 216, 380, 857, 730, 901, 493, 629, 271, 520, 862, 318, 672, 415, 943, 507, 390, 715, 628, 821, 534, 907, 302, 456, 781, 970, 642, 537, 280, 894, 710, 365, 190, 415, 630, 875, 209, 784, 431, 762, 689, 532, 940, 314, 219, 652, 802, 495, 327, 938, 714, 620, 351, 570, 813, 490, 264, 927, 756, 602, 385, 490, 739, 815, 608, 329, 924, 782, 453, 610, 987, 321, 658, 470, 925, 315, 713, 542, 821, 609, 301, 950, 728, 482, 364, 795, 421, 560, 833, 205, 318, 762, 481, 630, 745, 879, 502, 316, 721, 509, 284, 870, 759, 693, 610, 943, 207, 572, 450, 841, 609, 754, 312, 967, 514, 842, 231, 674, 890, 312, 765, 421, 520, 860, 719, 452, 791, 305, 658, 499, 752, 421, 308, 731, 987, 456, 892, 345, 612, 958, 234, 617, 807, 390, 629, 841, 205, 472, 693, 932, 714, 526, 719, 940, 231, 754, 418, 801, 592, 657, 874, 213, 587, 690, 835, 276, 571, 492, 908, 315, 703, 826, 419, 601, 752, 490, 263, 937, 654, 580, 319, 495, 739, 819, 604, 327, 925, 782, 453, 610, 987, 321, 658, 470, 925, 315, 713, 542, 821, 609, 301, 950, 728, 482, 364, 795, 421, 560, 833, 205, 318, 762, 481, 630, 745, 879, 502, 316, 721, 509, 284, 870, 759, 693, 610, 943, 207, 572, 450, 841, 609, 754, 312, 967, 514, 842, 231, 674, 890, 312, 765, 421, 520, 860, 719, 452, 791, 305, 658, 499, 752, 421, 308, 731, 987, 456, 892, 345, 612, 958, 234, 617, 807, 390, 629, 841, 205, 472, 693, 932, 714, 526, 719, 940, 231, 754, 418, 801, 592, 657, 874, 213, 587, 690, 835, 276, 571, 492, 908, 315, 703, 826, 419, 601, 752, 490, 263, 937, 654, 580, 319, 495, 739, 819, 604, 327, 925, 782, 453, 610, 987, 321, 658, 470, 925, 315, 713, 542, 821, 609, 301, 950, 728, 482, 364, 795, 421, 560, 833};
	// int sample[100] = {34, 451, 241, 915, 591, 941, 753, 219, 203, 490, 262, 68, 950, 156, 894, 915, 362, 741, 743, 220, 762, 527, 177, 220, 848, 634, 147, 365, 801, 992, 2, 96, 946, 154, 904, 974, 184, 65, 19, 545, 354, 242, 881, 535, 133, 213, 289, 411, 687, 399, 996, 820, 471, 248, 621, 476, 667, 144, 650, 945, 535, 89, 120, 460, 764, 702, 613, 439, 749, 197, 50, 247, 107, 525, 692, 365, 609, 519, 341, 747, 571, 476, 306, 942, 901, 94, 576, 581, 564, 992, 807, 335, 209, 19, 336, 715, 303, 858, 863, 212};
	Node *A = NULL, *B = NULL, *sorted = NULL;
	int i = 10;
	t_ops ops = {NULL, 0, 0};

	while (i >= 0)
	{
		insertAddHead(&A, sample[i]);
		insertAddHead(&sorted, sample[i]);
		i--;
	}
	displayForward(&A);
	SortList(&sorted);
	printf("sorted ");
	displayForward(&sorted);
	AddIndex(&A, &sorted);

	pushAtoB(&A, &B, &ops);
	printf("A ");
	displayForward(&A);
	printf("\n");
	printf("B ");
	displayForward(&B);

	pushBtoA(&A, &B, &ops);
	printf("A ");
	displayForward(&A);
	printf("B ");
	displayForward(&B);
	printf("\n");

	fix(&A, &ops);
	displayForward(&A);
	print_ops(&ops);
	free(ops.op_list);
	return (0);
}
