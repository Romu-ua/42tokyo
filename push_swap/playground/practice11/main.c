/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:22:51 by hyamamot          #+#    #+#             */
/*   Updated: 2025/02/18 17:22:53 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// nが小さいときは動作するが、nが１００程度になると無限ループする。
// おそらくget_elmが１とかなのがよくない。

#include "main.h"

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

void	final_fix(t_node **A, t_ops **ops)
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
		while (len - cnt - 1)
		{
			reverse_rotateA(A, ops);
			cnt++;
		}
	}
}

int	op_lengthList(t_ops **ops)
{
	t_ops	*tmp;
	int		len;

	if (!ops || !*ops)
		return (0);
	tmp = *ops;
	len = 1;
	while (tmp->pnext != *ops)
	{
		len++;
		tmp = tmp->pnext;
	}
	return (len);
}

int main(int argc, char **argv)
{
	t_node	*A;
	t_node	*B;
	t_node	*sorted;
	t_ops	*ops;

	if (argc == 1)
		return (0);
	A = NULL;
	B = NULL;
	sorted = NULL;
	ops = NULL;

	while (argc - 1)
	{
		insertAddHead(&A, atoi(argv[argc - 1]));
		insertAddHead(&sorted, atoi(argv[argc - 1]));
		argc--;
	}
	// printf("input A: ");
	// displayForward(&A);

	SortList(&sorted);
	AddIndex(&A, &sorted);
	half_push_B(&A, &B, &ops);

	// printf("half_push_B\n");
	// printf("A ");
	// displayForward(&A);
	// printf("B ");
	// displayForward(&B);

	// printf("--------------\n");

	operation(&A, &B, &ops);
	final_fix(&A, &ops);
	// displayForward(&A);
	print_ops(&ops);
	// if (!ops)
	// 	printf("ops is NULL");
	// printf("%d\n", op_lengthList(&ops));
	// printf("%d\n", ops->op);
	// ops = ops->pnext;
	// printf("%d", ops->op);
	return (0);
}
