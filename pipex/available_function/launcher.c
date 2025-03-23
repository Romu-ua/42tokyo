/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:54:10 by hyamamot          #+#    #+#             */
/*   Updated: 2025/03/23 18:54:11 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main()
{
	char	*argv[] = {"./a.out", "arg1", "arg2", NULL};
	char	*envp[] = {"EYVAR=HelloEnv", NULL};
	if (execve("./a.out", argv, envp) == -1) {
		perror("execve failed");
	}
	return (1);
}
