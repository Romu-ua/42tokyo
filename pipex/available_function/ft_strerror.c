/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:21:15 by hyamamot          #+#    #+#             */
/*   Updated: 2025/03/22 17:21:16 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

// 番号ごとにいろいろエラーメッセージが入っている
// errnoには関数が失敗したら数値が入るグローバル変数
int	main(void)
{
	int	fd;

	fd = open("./no_file", O_RDONLY);
	if (fd == -1)
	{
		printf("エラー番号 : %d\n", errno);
		printf("エラーメッセージ : %s\n", strerror(errno));
		printf("エラーメッセージ : %s\n", strerror(3));
	}
	return (0);
}
