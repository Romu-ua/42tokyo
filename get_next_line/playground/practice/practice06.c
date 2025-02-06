// ファイルを読み込んで改行が来たらそれまでを出力

#include <stdio.h>
#include <fcntl.h> // O_RDONLYを使うため
#include <unistd.h>

#define BUFFER_SIZE 10

void print_one_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			read_bytes;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[read_bytes] = '\0';
	printf("%s\n", buffer);
}

int main()
{

	int fd = open("test.txt", O_RDONLY);
	print_one_line(fd);
	printf("--------------\n");
	print_one_line(fd);
	printf("--------------\n");
	print_one_line(fd);
	printf("--------------\n");
	print_one_line(fd);
	printf("--------------\n");
	print_one_line(fd);
	close(fd);
	return (0);
}
