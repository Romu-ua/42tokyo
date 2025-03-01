// staticで静的領域に値が保持されていることの確認

#include <stdio.h>

void counter()
{
	static int count = 0;
	count++;
	printf("%d\n", count);
}

int main()
{
	int i;

	i = 0;
	while (i < 5)
	{
		counter();
		i++;
	}
	return (0);
}
