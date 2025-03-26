/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:36:30 by hyamamot          #+#    #+#             */
/*   Updated: 2025/03/23 18:36:31 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv, char **envp)
{
	// printf("Hello from execve!\n");
	// for (int i = 0; i < argc; i++) {
	// 	printf("argv[%d] = %s\n", i, argv[i]);
	// }

	// どちらかのexecveしか実行されない
	// char *input[] = {".", NULL};
	// execve("/bin/pwd", input, envp);
	// execve("/bin/ls", input, envp);

	char *args[] = {"/bin/ls", "-l", "../", NULL};
	execve("/bin/ls", argv, envp);


	return (0);
}
