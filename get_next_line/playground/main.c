#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main() {
	int	i;
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

	i = 0;
    char *line;
    while ((line = get_next_line(fd))) { // 1行ずつ取得
        printf("-------------\n");
		printf("%d : %s\n", i, line);
		printf("-------------\n");
		i++;
        free(line); // ヒープ領域を解放
    }

    close(fd);
    return 0;
}
