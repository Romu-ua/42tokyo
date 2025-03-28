/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:28:06 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 16:01:34 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"


void			ft_print_result(int n)
{
	char c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

static void		check_strlcpy(char *dest, char *src, int size, int dest_len)
{
	ft_print_result(ft_strlcpy(dest, src, size));
	write(1, "\n", 1);
	write(1, dest, dest_len);
	free(dest);
}

int				main(int argc, const char *argv[])
{
	char	*dest;
	int		arg;
	int		dest_len;

	alarm(5);
	dest_len = 15;
	if (!(dest = (char *)malloc(sizeof(*dest) * dest_len)) || argc == 1)
		return (0);
	memset(dest, 0, dest_len);
	memset(dest, 'r', 6);
	if ((arg = atoi(argv[1])) == 1)
		check_strlcpy(dest, "lorem", 15, dest_len);
	else if (atoi(argv[1]) == 2)
		check_strlcpy(dest, "", 15, dest_len);
	else if (atoi(argv[1]) == 3)
		check_strlcpy(dest, "lorem ipsum", 3, dest_len);
	else if (atoi(argv[1]) == 4)
		check_strlcpy(dest, "lorem ipsum dolor sit amet", 15, dest_len);
	else if (atoi(argv[1]) == 5)
		check_strlcpy(dest, "lorem ipsum dolor sit amet", 0, dest_len);
	return (0);
}
