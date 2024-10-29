#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/libft.h"

int run_test(size_t size) {
	if (size == 0){
		// malloc(0)が未定義動作
		return 0;
	}
	char *std_buffer = malloc(size);
	char *custom_buffer = malloc(size);

	if (!std_buffer || !custom_buffer) {
		fprintf(stderr, "Memory allocation failed\n");
		return 1;
	}

	// 標準のbzeroと自作のft_bzeroを使ってバッファを初期化
	bzero(std_buffer, size);
	ft_bzero(custom_buffer, size);

	int result = memcmp(std_buffer, custom_buffer, size);

	if (result == 1) {
		printf("FAILED\n");
	}

	free(std_buffer);
	free(custom_buffer);

	return result;
}

int main(void) {
	int failed_tests = 0;

	failed_tests += run_test(0);
    failed_tests += run_test(10);
    failed_tests += run_test(42);

	if (failed_tests == 0) {
		printf("All tests passed!\n");
	} else {
		printf("%d test failed\n", failed_tests);
	}
	return failed_tests;
}
