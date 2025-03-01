#include <stdio.h>
#include <string.h>  // 標準の memset を使うため
#include <stdlib.h>  // malloc, free を使うため
#include "../includes/libft.h"

int run_test(const char *test_name, size_t size, int value) {
    char *std_buffer = malloc(size);
    char *custom_buffer = malloc(size);

    if (!std_buffer || !custom_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // 標準の memset と自作 ft_memset を使ってバッファを初期化
    memset(std_buffer, value, size);
    ft_memset(custom_buffer, value, size);

	printf("%d %d\n", std_buffer[0],custom_buffer[0]);

    // バッファの比較
    int result = memcmp(std_buffer, custom_buffer, size);

    // 結果の出力
    if (result == 0) {
        printf("%s: PASSED\n", test_name);
    } else {
        printf("%s: FAILED\n", test_name);
    }

    // メモリの解放
    free(std_buffer);
    free(custom_buffer);

    return result;
}

int main(void) {
    int failed_tests = 0;

    // 各テストケースを実行
    failed_tests += run_test("Test 1: Zero fill", 10, 0);
    failed_tests += run_test("Test 2: Fill with 'A'", 10, 'A');
    failed_tests += run_test("Test 3: Fill with 255", 10, 255);
    failed_tests += run_test("Test 4: Large buffer", 10000, 1);
	failed_tests += run_test("Test 5 Fill with 256", 256, 256);
	failed_tests += run_test("Test 6 Fill with 257", 257, 257);
	failed_tests += run_test("Test 7 Fill with 258", 258, 258);

    // 結果の表示
    if (failed_tests == 0) {
        printf("All tests passed!\n");
    } else {
        printf("%d tests failed.\n", failed_tests);
    }

    return failed_tests;
}
