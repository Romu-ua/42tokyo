// コマンドを探す機構と実行する機構を組み合わせる

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char	*find_cmd(char *cmd, char **envp);
char	*cmd(char *arg, char **envp);

// libft
size_t	ft_strlen(const char *s);
char    **ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		count_word(char const *s, char c);



int main(int argc, char **argv, char **envp)
{
	char	**cmd_opts;
	int		size;
	int		i;
	char	*cmd1;
	char	*cmd2;

	int		pid1;
	int		pid2;
	int		pipefd[2];
	int		status;
	int		fd;

	if (argc < 2)
		return (1);

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}

	pid1 = fork();
	if (pid1 < 0)
	{
		perror("fork");
		return (1);
	}
	else if (pid1 == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		cmd_opts = ft_split(argv[2], ' ');
		cmd1 = cmd(cmd_opts[0], envp);
		execve(cmd1, cmd_opts, envp); // 書き込み口は明示的には閉じてないが、子プロセスの終了とともに閉じられている？
	}

	waitpid(pid1, &status, 0);
	close(pipefd[1]);
	pid2 = fork();
	if (pid2 < 0)
	{
		perror("fork");
		return (1);
	}
	else if (pid2 == 0)
	{
		close(pipefd[1]);
		fd = open(argv[4], O_WRONLY | O_TRUNC);
		dup2(fd, 1);
		dup2(pipefd[0], 0);
		cmd_opts = ft_split(argv[3], ' ');
		cmd2 = cmd(cmd_opts[0], envp);
		execve(cmd2, cmd_opts, envp);
	}
	waitpid(pid2, &status, 0);
	return (0);
}

char	*cmd(char *arg, char **envp)
{
	char	*cmd;

	if (access(arg, X_OK) != -1)
		cmd = arg;
	else
	{
		cmd = find_cmd(arg, envp);
		if (!cmd)
			return (NULL);
	}
	return (cmd);
}

char	*find_path(char **envp)
{
	int		i;
	char	**split;

	i = 0;
	while (1)
	{
		if (!envp[i])
			return (NULL);
		if (!ft_strncmp(envp[i], "PATH", 4))
			break ;
		i++;
	}
	return (envp[i] + 5);
}

char	*find_cmd(char *cmd, char **envp)
{
	int		i;
	int		exist;
	char	**split;
	char	*file;
	char	*path;

	path = find_path(envp);
	if (!path)
		return (NULL);
	split = ft_split(path, ':');
	cmd = ft_strjoin("/", cmd);
	i = 0;
	while (1)
	{
		if (!split[i])
			return (NULL);
		file = ft_strjoin(split[i], cmd);
		if (access(file, F_OK) != -1)
			return (file);
		i++;
	}
	return (NULL);
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

char	**ft_split(char const *s, char c)
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
