#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int main()
{
	void	*buf;
	int		fd;
	ssize_t	byte;

	buf = malloc(BUFFER_SIZE);
	printf("BUFFER_SIZE is %d\n", BUFFER_SIZE);
	fd = open("./test_file.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while((byte = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		printf("read!!!\n");
		write(STDOUT_FILENO, buf, byte);
		printf("----\n");
	}
	return (0);
}
