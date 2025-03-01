// 今回は禁止だが、グローバルに変数を配置
// グローバルに変数を配置することで、これも静的領域に保持される
// 初期化していると静的領域、初期化しないもしくは０で明示的に初期化はBSS領域
// staticをつけないグローバル変数は別のファイルから編集可能

#include <stdio.h>

void other_modify();

int practice01;
int practice02 = 1;


void modify_global()
{
	practice01++;
	practice02 += 2;
	printf("%d, %d\n", practice01, practice02);
}

int main()
{
	modify_global();
	modify_global();
	modify_global();

	other_modify();
	other_modify();
	other_modify();

	return (0);
}
