// ファイルを読み込んで改行が来たらそれまでを出力

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while(*str++)
		len++;
	return (len);
}

void	ft_strcpy(char *new_line, char *str)
{
	while (!(*str))
	{
		*new_line = *str;
		new_line++;
		str++;
	}
}

char *ft_strjoin(char *s1, char *s2)
{
	// s1とs2の長さを測ってmallocして文字列を結合して返す
	int		lens1;
	int		lens2;
	char	*new_line;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	new_line = (char *)malloc((lens1 + lens2) * sizeof(char));
	if (!new_line)
		return (NULL);
	if (!lens1)
		ft_strcpy(new_line, s1);
	if (!lens2)
		ft_strcpy(new_line + lens1, s2);
	free(s1);
	return (new_line);
}

char *find_newline(char *buffer)
{
	while (*buffer)
	{
		if (*buffer == '\n')
			return (buffer);
		buffer++;
	}
	return (NULL);
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char		*line; // returnする１行全体
	char		*newline_pos;
	int			read_bytes;

	line = NULL;
	while (1)
	{
		// もしbufferが空なら読み込む
		if (!(*buffer))
		{
			read_bytes = read(fd, buffer, BUFFER_SIZE);
			// readはerrorで-1, EOFで0
			if (buffer <= 0)
				return (line);
			// 終端文字をつけないと文字列として処理しずらい
			buffer[BUFFER_SIZE] = '\0';
		}

		// bufferの中に値がある時
		// newline_posはbufferのポインタ
		newline_pos = find_newline(buffer);
		if (newline_pos)
		{
			// 改行をnull文字に変換する
			*newline_pos = '\0';
			line = ft_strjoin(line, buffer);
			memmove(buffer, newline_pos, strlen(newline_pos + 1));
			return (line);
		}
		// 改行がない時
		else
		{
			line = ft_strjoin(line, buffer);
			// 先頭を空にすることで文字列的には何もないということを表現
			*buffer = '\0';
		}
	}
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	print_one_line(fd);
	return (0);
}
