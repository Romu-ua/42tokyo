/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 19:41:55 by hyamamot          #+#    #+#             */
/*   Updated: 2025/03/23 19:41:55 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

// pipeの引数は書き込み用と読み込み用のfdが入る（添え字0が読み込み用、1が書き込み用）
int	main()
{
	int		pipefd[2];
	pid_t	pid;
	char	buf[100];

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}

	pid = fork();

	if (pid < 0)
	{
		perror("fork error");
		return (1);
	}
	else if (pid == 0)
	{
		// 子プロセス
		close(pipefd[1]); //書き込み用の口(ファイル)を閉じる
		read(pipefd[0], buf, sizeof(buf));
		printf("child received : %s\n", buf);
		close(pipefd[0]);
	}
	else
	{
		close(pipefd[0]); //読み込み用の口(ファイル)を閉じる
		const char *msg = "Hello from parent!";
		write(pipefd[1], msg, strlen(msg) + 1);
		close(pipefd[1]);
		// 書き込み口を閉じたことで、子プロセスのreadが解除される
	}
	return (0);
}
