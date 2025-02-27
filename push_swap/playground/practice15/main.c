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

#include "main.h"

void	free_node_all(t_node **stack)
{
	t_node	*next;
	t_node	*tmp;
	t_node	*head;

	head = *stack;
	tmp = head;
	if (!stack || !*stack)
		return ;
	while (1)
	{
		next = tmp->pnext;
		free(tmp);
		if (next == head)
			break ;
		tmp = next;
	}
	*stack = NULL;
}

void	free_ops_all(t_ops **ops)
{
	t_ops	*head;
	t_ops	*tmp;
	t_ops	*next;

	if (!ops || !*ops)
		return ;
	head = *ops;
	tmp = head;
	while (1)
	{
		next = tmp->pnext;
		free(tmp);
		if (next == head)
			break ;
		tmp = next;
	}
	*ops = NULL;
}

void	frees(t_node **A, t_node **sorted, t_ops **ops)
{
	free_node_all(A);
	free_node_all(sorted);
	free_ops_all(ops);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	t_node	*sorted;
	t_ops	*ops;
	int		i;

	if (argc == 1 || input_check(argc, argv))
		return (0);
	i = argc;
	while (i-- > 1)
	{
		insert_add_head(&a, ft_atol(argv[i]));
		insert_add_head(&sorted, ft_atol(argv[i]));
	}
	sort_list(&sorted);
	add_index(&a, &sorted);
	if (argc <= 7)
		simple_sort(&a, &b, &ops, argc - 1);
	else
		operation(&a, &b, &sorted, &ops);
	print_ops(&ops);
	frees(&a, &sorted, &ops);
	return (0);
}
