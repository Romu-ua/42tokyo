/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:33:33 by hyamamot          #+#    #+#             */
/*   Updated: 2025/03/22 17:33:34 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

// 現在の実行ユーザーの権限でアクセスできるかどうか
// -rw-r--r-- file1,2の権限
int	main(int argc, char **argv, char **envp)
{
	// if (access("./file1", (R_OK)))
	// 	return (1);
	// printf("file1は読み取りできる\n");
	// if (access("./file2", (R_OK | X_OK)))
	// {
	// 	perror("accessでエラーが発生!");
	// 	return (1);
	// }
	int i = 0;
	while (1)
	{
		if (!envp[i])
			break;
		if (!strncmp(envp[i], "PATH", 4))
			break;
		printf("%s\n", envp[i]);
		i++;
	}
	printf("-----------\n");
	printf("%s\n", envp[i]);
	// ファイルの存在判定
	if (access("/bin/ls", F_OK) == -1)
		printf("file don't exist\n");
	else
		printf("file exist");



	return (0);
}
