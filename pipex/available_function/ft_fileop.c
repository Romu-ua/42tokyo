/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fileop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:46:30 by hyamamot          #+#    #+#             */
/*   Updated: 2025/03/22 16:58:41 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define BUF_SIZE 512

// open read write closeについて学習
int	main(void)
{
	int		fd1;
	int		fd2;
	int		byte_num;
	char	buf[BUF_SIZE];

	fd1 = open("./file1", O_RDONLY);
	fd2 = open("./file2", O_WRONLY);
	if (fd1 == -1 || fd2 == -1)
		return (1);
	byte_num = read(fd1, &buf[0], 5);
	if (byte_num == -1)
		return (1);
	buf[byte_num] = '\0';
	printf("read 5 byte : %s\n", buf);
	byte_num = write(fd2, &buf[0], 5);
	if (byte_num == -1)
		return (1);
	close(fd1);
	close(fd2);
	return (0);
}
