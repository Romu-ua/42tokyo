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

void	frees(t_node **a, t_ops **ops)
{
	free_node_all(a);
	free_ops_all(ops);
}

int main(int argc, char **argv)
{
	t_node	*a;
	t_ops	*ops;
	int		i;

	a = NULL;
	ops = NULL;
	if (argc == 1 || input_check(argc, argv))
		return (0);
	i = argc;
	while (i > 1)
	{
		insert_add_head(&a, ft_atol(argv[i - 1]));
		i--;
	}

	addidx(&a, argv);
	i = 0;
	while (i < argc - 1)
	{
		printf("%d ", a->index);
		a = a->pnext;
		i++;
	}
	if (argc <= 7)
		simple_sort(&a, &ops, argc - 1);
	// else
	// 	operation(&a, &ops);
	print_ops(&ops);
	frees(&a, &ops);
	return (0);
}
