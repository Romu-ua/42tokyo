// 別のファイルからアクセスしてみる(エラーになる)

#include <stdio.h>

// extern static int file_scope_value; // 静的コンパイルの時点でエラーが発生

// void other_modify()
// {
// 	file_scope_value += 10;
// 	printf("%d\n", file_scope_value);
// }
