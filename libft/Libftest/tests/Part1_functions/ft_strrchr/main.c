/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:08:30 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:48:43 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

static void		ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void		check_strrchr(char *s, int c, int offset)
{
	char		*str;
	
	if (!(str = ft_strrchr(s, c)))
		ft_print_result("NULL");
	else
	{
		ft_print_result(str);
		if (str != (s + offset))
			ft_print_result("\nReturn value is false");
	}
}

int				main(int argc, const char *argv[])
{
	char		str2[] = "bonjour";
	int			arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		check_strrchr(str2, 'b', 0);
	else if (arg == 2)
		check_strrchr(str2, 'o', 4);
	else if (arg == 3)
	{
		char	str3[]= "bonjourno";

		check_strrchr(str3, 'o', 8);
	}
	else if (arg == 4)
		check_strrchr(str2, 'j', 3);
	else if (arg == 5)
		check_strrchr(str2, 's', 0);
	else if (arg == 6)
		check_strrchr(str2, '\0', 7);
	else if (arg == 7)
	{
		char	str3[] = "";

		check_strrchr(str3, '\0', 0);
	}
	else if (arg == 8)
		check_strrchr(str2 + 2, 'b', 0);
	return (0);
}
