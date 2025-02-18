/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:50:56 by hyamamot          #+#    #+#             */
/*   Updated: 2025/02/17 17:51:01 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// デバック用
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

void	final_fix(t_node **A, t_ops *ops)
{
	t_node *tmp;
	int		len;
	int		cnt;

	len = lengthList(A);
	tmp = *A;
	cnt = 0;
	while (tmp->pnextnode != *A)
	{
		// printf("cnt : %d\n", cnt);
		if (tmp->index == 0)
			break;
		tmp = tmp->pnextnode;
		cnt++;
	}
	if (cnt < len / 2)
	{
		while (cnt)
		{
			rotateA(A, ops);
			cnt--;
		}
	}
	else
	{
		while (len - cnt)
		{
			reverse_rotateA(A, ops);
			cnt++;
		}
	}
}

int main(int argc, char **argv)
{
	t_node	*A;
	t_node	*B;
	t_node	*sorted;
	t_ops	ops;

	if (argc == 1)
		return (0);
	A = NULL;
	B = NULL;
	sorted = NULL;
	ops.size = 0;
	ops.capacity = 10;
	ops.op_list = (t_op *)malloc(sizeof(t_op) * ops.capacity);
	if (!ops.op_list)
		return (1);

	while (argc - 1)
	{
		insertAddHead(&A, atoi(argv[argc - 1]));
		insertAddHead(&sorted, atoi(argv[argc - 1]));
		argc--;
	}
	SortList(&sorted);
	AddIndex(&A, &sorted);

	half_push_B(&A, &B, &ops);

	// // debug できている
	// displayForward(&A);
	// displayForward(&B);


	operation(&A, &B, &ops);
	// printf("after operation A : ");
	// displayForward(&A);

	final_fix(&A, &ops);
	displayForward(&A);

	print_ops(&ops);
	return (0);
}
