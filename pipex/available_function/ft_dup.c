/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:44:52 by hyamamot          #+#    #+#             */
/*   Updated: 2025/03/22 17:44:53 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void	sample(void);

// dup,dup2について
// ファイルディスクリプタを一時的に複製するための関数
// 主に標準入力・出力・エラーを差し替える(リダイレクト)ときに使う
int	main(void)
{
	int fd;
	int	save_stdout;

	fd = open("./output", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	save_stdout = dup(1);
	dup2(fd, 1);
	printf("これはファイルに出力されます\n");
	dup2(save_stdout, 1);
	printf("これは画面に出力されます\n");
	close(fd);
	close(save_stdout);
	sample();
	return (0);
}

// ./a.out > output.txt 2>&1
// このコマンドをdup,dup2で再現する
void	sample(void)
{
	int	fd;

	fd = open("./output", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	dup2(fd, 1);
	dup2(fd, 2);
	close(fd);
	printf("this is stdout\n");
	fprintf(stderr, "This is stderr\n");
}
