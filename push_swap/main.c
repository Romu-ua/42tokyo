#include "main.h"

int main(int argc, char **argv)
{
	t_node	*a;
	t_ops	*ops;
	int		i;

	if (argc == 1 || input_check(argc, argv))
		return (0);
	i = 0;
	while (i < argc)
	{
		insert_add_head(&a, ft_atol(argv[i]));
		i++;
	}
	addidx(&a);
	if (argc <= 7)
		simple_sort(&a, &ops, argc - 1);
	else
		operation(&a, &ops);
	print_ops(ops);
	frees(&a, &ops);
	return (0);
}
