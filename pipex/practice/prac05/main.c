/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prac05.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamamototaimu <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:36:30 by yamamototaimu     #+#    #+#             */
/*   Updated: 2025/03/25 19:36:32 by yamamototaimu    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "pipex.h"

static void	process(char **argv, char **envp);

// prac04で基本的な構造はできたので、エラー処理を書いていく
// 一応 norminetteを気にする
// TODO infileの存在確認のエラーハンドリングが不自然。しかし表示内容はあっている。
int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		return (1);
	if (access(argv[1], F_OK | R_OK) == -1)
	{
		perror("bash: infile");
		return (0);
	}
	process(argv, envp);
	return (0);
}

static void	first_cmd(int *pipefd, char **argv, char **envp)
{
	char	**cmd_opts;
	char	*cmd;
	int		fd;

	close(pipefd[0]);
	dup2(pipefd[1], 1);
	fd = open(argv[1], F_OK | R_OK);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	dup2(fd, 0);
	cmd_opts = ft_split(argv[2], ' ');
	cmd = ft_cmd(cmd_opts[0], envp);
	execve(cmd, cmd_opts, envp);
	perror("execve");
	exit(1);
}

static void	second_cmd(int *pipefd, char **argv, char **envp)
{
	int		fd;
	char	**cmd_opts;
	char	*cmd;

	close(pipefd[1]);
	if (access(argv[4], F_OK) == 0)
		fd = open(argv[4], O_WRONLY | O_TRUNC);
	else
		fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	dup2(fd, 1);
	dup2(pipefd[0], 0);
	cmd_opts = ft_split(argv[3], ' ');
	cmd = ft_cmd(cmd_opts[0], envp);
	execve(cmd, cmd_opts, envp);
}

static void	show_error(void)
{
	perror("fork");
	exit(1);
}

// エラーで１を返す
static void	process(char **argv, char **envp)
{
	int		pid1;
	int		pid2;
	int		pipefd[2];
	int		status;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	pid1 = fork();
	if (pid1 < 0)
		show_error();
	else if (pid1 == 0)
		first_cmd(pipefd, argv, envp);
	waitpid(pid1, &status, 0);
	close(pipefd[1]);
	pid2 = fork();
	if (pid2 < 0)
		show_error();
	else if (pid2 == 0)
		second_cmd(pipefd, argv, envp);
	waitpid(pid2, &status, 0);
	exit(0);
}
