// staticをつけるグローバル変数は他のファイルから編集不可能

#include <stdio.h>

// void other_modify();

static int file_scope_value = 1;

void test_scope()
{
	file_scope_value++;
	printf("%d\n", file_scope_value);
}

int main()
{
	test_scope();
	test_scope();
	test_scope();
	return (0);
}
