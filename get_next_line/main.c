#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int fd = open("test.txt", O_RDONLY);
	while (1)
	{
		char *test = get_next_line(fd);
		if (!test)
			break;
		printf("%s\n", test);
		free(test); // mainの方でフリーするよな
	}
	close(fd);
	return (0);
}
