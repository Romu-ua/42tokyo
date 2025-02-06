// ファイルを読み込んで改行が来たらそれまでを出力

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 20

void print_one_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			read_bytes;


}

int main()
{

	int fd = open("test.txt", O_RDONLY);
	print_one_line(fd);
	return (0);
}
