/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:05:29 by hyamamot          #+#    #+#             */
/*   Updated: 2025/02/22 13:05:31 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	qsort(arr, argc - 1, sizeof(int), compare);
	i = 0;
	while (i < argc - 2)
	{
		if (arr[i] == arr[i + 1])
		{
			printf("Error: duplicates\n");
			return (1);
		}
		i++;
	}
	free(arr);
	return (0);
}

int	digit_check(char *nptr, int j)
{
	int	flag;

	flag = 0;
	while (nptr[j])
	{
		if (!ft_isdigit(nptr[j]))
			flag = 1;
		j++;
	}
	return (flag);
}

int	char_check(int argc, char **argv)
{
	int	i;
	int	j;
	int	input;
	int	flag;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (argv[i][j] == '\0')
			flag = 1;
		flag = digit_check(argv[i], j);
		input = ft_atol(argv[i]);
		if (input > INT_MAX || input < INT_MIN)
			flag = 1;
		i++;
	}
	if (flag)
	{
		printf("Error: char_check\n");
		return (flag);
	}
	return (0);
}

int	input_check(int argc, char **argv)
{
	int		flag;

	flag = char_check(argc, argv);
	if (flag)
		return (flag);
	flag = duplicates_check(argc, argv);
	return (flag);
}
