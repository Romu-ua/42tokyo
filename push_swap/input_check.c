#include "main.h"

int	digit_check(char *nptr, int j)
{
	int	flag;

	flag = 0;
	while (nptr[j])
	{
		if (nptr[j] < '0' || nptr[j] > '9')
			flag = 1;
		j++;
	}
	return (flag);
}

int	char_check(int argc, char **argv)
{
    long	input;
    int		flag;
    int		i;
    int		j;

	flag = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (argv[i][j] == '\0')
			flag = 1;
		flag |= digit_check(argv[i], j);
		input = ft_atol(argv[i]);
		if (input < INT_MIN || input > INT_MAX)
			flag = 1;
		i++;
	}
	if (flag)
		write(1, "Error\n", 6);
	return (flag);
}

void	ft_sort(int *arr, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	duplicates_check(int argc, char **argv)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (!arr)
		return (1);
	i = 0;
	while (i < argc - 1)
	{
		arr[i] = ft_atol(argv[i + 1]);
		i++;
	}
	ft_sort(arr, argc - 1);
	while (1 < i)
	{
		if (arr[i - 1] == arr[i - 2])
		{
			write(1, "Error\n", 6);
			free(arr);
			return (1);
		}
		i--;
	}
	free(arr);
	return (0);
}

int	input_check(int argc, char **argv)
{
    int	flag;

    flag = char_check(argc, argv);
	if (flag == 0)
		flag = duplicates_check(argc, argv);
    return (flag);
}
