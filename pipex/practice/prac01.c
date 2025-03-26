/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prac01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamamototaimu <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:09:52 by yamamototaimu     #+#    #+#             */
/*   Updated: 2025/03/23 21:09:52 by yamamototaimu    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ファイルを発見するところまで記述した。

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);
char    **ft_sprit(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (i < n)
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (c1 != c2)
			return (c1 - c2);
		if (c1 == '\0')
			break ;
		i++;
	}
	return (0);
}

// コマンドを全て実装するわけにはいかない。
// accessを使ってコマンドを使うのだと思う。
// macは/bin linuxはusr/bin
int	main(int argc, char **argv, char **envp)
{
	int		i;
	char	**split;

	// if (argc < 2)
	// 	return (1);
	// if (access(argv[1], R_OK | W_OK) || access(argv[4], R_OK | W_OK))
	// {
	// 	perror("access");
	// 	return (1);
	// }
	// コマンドがあるかどうかを探す
	i = 0;
	while (1)
	{
		if (!envp[i])
			break;
		if (!ft_strncmp(envp[i], "PATH", 4))
			break;
		i++;
	}
	printf("%s\n", envp[i]);
	split = ft_sprit(envp[i] + 5, ':');
	i = 0;
	char *file;
	while (1)
	{
		if (!split[i])
			break ;
		file = ft_strjoin(split[i], "/ls");
		if (access(file, F_OK) == -1)
		{
			printf("%s : file don't exist\n", file);
		}
		else
		{
			printf("%s file is found\n", file);
			break;
		}
		i++;
		// 中身の確認 bin/があるのでここで反応してほしい
		// printf("%s\n", split[i]);
		// i++;
	}
	printf("%s\n", file);

	return (0);
}


// ------ファイルに分けるのがめんどくさいのでここに書いてく------

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens1;
	int		lens2;
	int		i;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < lens1)
		result[i] = s1[i];
	i = -1;
	while (++i < lens2)
		result[lens1 + i] = s2[i];
	result[lens1 + lens2] = '\0';
	return (result);
}

// 今見ている文字が区切り文字でなくて、前回の文字が区切り文字の時 cnt+1する
int	count_word(char const *s, char c)
{
	int	cnt;
	int	in_substring;

	cnt = 0;
	in_substring = 0;
	while (*s)
	{
		if (*s != c && in_substring == 0)
		{
			in_substring = 1;
			cnt++;
		}
		else if (*s == c)
			in_substring = 0;
		s++;
	}
	return (cnt);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

void	free_all(char	**result, int j)
{
	while (j >= 0)
	{
		free(result[j]);
		j--;
	}
	free(result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*subs;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		subs = (char *)malloc(1);
		if (!subs)
			return (NULL);
		subs[0] = '\0';
		return (subs);
	}
	if (len > s_len - start)
		len = s_len - start;
	subs = (char *)malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (NULL);
	ft_strlcpy(subs, &s[start], len + 1);
	return (subs);
}

int	split_word(char const *s, char c, char **result)
{
	int	i;
	int	j;
	int	start;
	int	is_terminal;

	i = 0;
	j = 0;
	is_terminal = 0;
	start = -1;
	while (s[i])
	{
		if (s[i] != c && start < 0)
			start = i;
		if ((s[i] == c || s[i + 1] == '\0') && start >= 0)
		{
			is_terminal = (s[i + 1] == '\0' && s[i] != c);
			result[j] = ft_substr(s, start, i - start + is_terminal);
			if (!result[j++])
				return (-1);
			start = -1;
		}
		i++;
	}
	return (j);
}

char	**ft_sprit(char const *s, char c)
{
	char	**result;
	int		word_cnt;

	if (!s)
		return (NULL);
	word_cnt = count_word(s, c);
	result = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!result)
		return (NULL);
	if (split_word(s, c, result) == -1)
	{
		free_all(result, word_cnt);
		return (NULL);
	}
	result[word_cnt] = NULL;
	return (result);
}
