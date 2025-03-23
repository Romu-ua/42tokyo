/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 19:26:46 by hyamamot          #+#    #+#             */
/*   Updated: 2025/03/23 19:26:46 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// argcはexecve関数が計算しているのではなくて、カーネルが新しいプロセスを起動するときに計算
int	main(int argc, char **argv, char **envp)
{
	printf("Hello from execve!\n");
	for (int i = 0; i < argc; i++) {
		printf("argv[%d] = %s\n", i, argv[i]);
	}
	return (0);
}
