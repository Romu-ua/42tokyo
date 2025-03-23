/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unlink.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:40:46 by hyamamot          #+#    #+#             */
/*   Updated: 2025/03/23 20:40:46 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	const char	*filename = "sample";
	int			fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	write(fd, "This file is still alive!\n", 26);
	close(fd);

	// もう一度開く
	fd = open(filename, O_RDONLY);
	// 開いたままunlink
	if (unlink(filename) == 0)
		printf("ファイル %s を削除しました\n", filename);
	else
		perror("ファイルの削除に失敗 unlink");


	// ファイル名(参照)を削除しただけだから、ファイルを開いていれば本体は見れる
	char	buf[128];
	ssize_t n = read(fd, buf, sizeof(buf) - 1);
	if (n > 0) {
		buf[n] = '\0';
		printf("読み取った内容 %s \n", buf);
	} else {
		perror("read");
	}
	close(fd);
	printf("ファイルへの参照が０になったので本体も削除される\n");
	return (0);
}
