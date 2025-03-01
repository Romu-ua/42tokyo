// constとstaticの組み合わせ
#include <stdio.h>

static const int MAX_COUNT = 10; // 外部ファイルから編集されない値
const static int MIN_COUNT = 1;  // 同じ意味

void print_max()
{
	printf("%d\n", MAX_COUNT);
	// MAX_COUNT++;
}

int main()
{
	print_max();
	return (0);
}
