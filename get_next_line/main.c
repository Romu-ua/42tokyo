#include <stdio.h>
#include "get_next_line.h"

int main()
{
	char *input;

	line = (char *)malloc(BUFFER_SIZE);
	while(line=get_next_line(fd))
	{
		printf("%s", line);
	}
	return (0);
}
