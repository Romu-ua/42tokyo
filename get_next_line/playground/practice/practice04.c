// 静的変数とローカル変数

#include <stdio.h>

void test_static()
{
	static int s = 1;
	int a = 1;

	s++;
	a++;

	printf("%d, %d\n", s, a);
}

int main()
{
	test_static();
	test_static();
	test_static();
	return (0);
}
