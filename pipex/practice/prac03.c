// pipeの挙動を確かめる

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipefd[2];
	int		status;

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
		// 子プロセス
		close(pipefd[0]); //読み込み口を閉じる
		dup2(pipefd[1], 1); // 標準出力をpipeの書き込み口に向ける
		char *args[] = {"/bin/ls", "-a", NULL};
		execve("/bin/ls", args, envp);
	}
	waitpid(pid1, &status, 0); // waitpidの引数はnotionにまとめた
	close(pipefd[1]); // 書き込み口を閉じる
	// char buf[100];
	// read(pipefd[0], buf, 100);
	// printf("printf : %s", buf); // 読み取れてる！

	pid2 = fork();

	if (pid2 < 0)
	{
		perror("fork");
		return (1);
	}
	else if (pid2 == 0)
	{
		dup2(pipefd[0], 0); // 読み込み口を標準入力に向ける
		int fd = open("./outfile", O_WRONLY | O_TRUNC);
		dup2(fd, 1); // 出力をoutfileに向ける
		char *args[] = {"/bin/wc", "-l", NULL};
		close(pipefd[1]); // 入力口を閉じる
		execve("/usr/bin/wc", args, envp); // 無限ループ。wcが入力待ち
	}

	// 親プロセス
	waitpid(pid2, &status, 0);


	return (0);
}
