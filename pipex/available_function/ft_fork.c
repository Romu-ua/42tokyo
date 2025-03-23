/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:58:47 by hyamamot          #+#    #+#             */
/*   Updated: 2025/03/23 18:58:48 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


// int sample(void);

int	main(void)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork failed\n");
		return (1);
	}
	else if (pid == 0)
	{
		// 子プロセス
		char	*argv[] = {"./hello", "arg1", NULL};
		char 	*envp[] = {NULL};
		printf("child: ececuting hello ...\n");

		if (execve("./hello", argv, envp) == -1)
			perror("execve failed");
		return (1);
	}
	else
	{
		// 親プロセス
		int status;
		printf("Parent: waiting for child ... \n");
		waitpid(pid, &status, 0);
		printf("Parent: child exited with status %d\n", WEXITSTATUS(status));
	}
	return (0);
}

// プロセスチェック
// int	sample(void)
// {
// 	pid_t pid = fork();

// 	if (pid == 0)
// 		printf("This is the child process. PID: %d\n", getpid());
// 	else
// 		printf("This is the perent process. PID: %d\n", getpid());

// 	return (0);
// }
