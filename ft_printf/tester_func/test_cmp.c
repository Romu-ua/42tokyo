#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>

#include "../ft_printf/includes/ft_printf.h"

void test_cmp(const char *format, ...)
{
    int std_fd, ft_fd, saved_stdout;
    char std_buffer[1024], ft_buffer[1024];
    FILE *std_file, *ft_file;
    int std_return, ft_return;
    va_list args;

    saved_stdout = dup(STDOUT_FILENO); // 元の標準出力を保存
    if (saved_stdout == -1) {
        perror("dup");
        exit(EXIT_FAILURE);
    }

    // 標準 printf の結果を取得
    std_fd = open("std_out.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (std_fd == -1) {
        perror("open std_out.txt");
        close(saved_stdout);
        exit(EXIT_FAILURE);
    }
    dup2(std_fd, STDOUT_FILENO); // 標準出力をリダイレクト
    va_start(args, format);
    std_return = vprintf(format, args);
    va_end(args);
    fflush(stdout);
    close(std_fd);

    // 自作 ft_printf の結果を取得
    ft_fd = open("ft_out.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (ft_fd == -1) {
        perror("open ft_out.txt");
        dup2(saved_stdout, STDOUT_FILENO);
        close(saved_stdout);
        exit(EXIT_FAILURE);
    }
    dup2(ft_fd, STDOUT_FILENO); // 標準出力をリダイレクト
    va_start(args, format);
    ft_return = ft_printf(format, args);
    va_end(args);
    fflush(stdout);
    close(ft_fd);

    // 標準出力を元に戻す
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);

    // ファイルから出力内容を読み取る
    memset(std_buffer, 0, sizeof(std_buffer));
    memset(ft_buffer, 0, sizeof(ft_buffer));

    std_file = fopen("std_out.txt", "r");
    ft_file = fopen("ft_out.txt", "r");
    if (!std_file || !ft_file) {
        perror("fopen");
        if (std_file) fclose(std_file);
        if (ft_file) fclose(ft_file);
        remove("std_out.txt");
        remove("ft_out.txt");
        exit(EXIT_FAILURE);
    }

    fread(std_buffer, 1, sizeof(std_buffer) - 1, std_file);
    fread(ft_buffer, 1, sizeof(ft_buffer) - 1, ft_file);

    // 出力内容の比較
    if (strcmp(std_buffer, ft_buffer) == 0) {
        printf("SUCCESS: Outputs match for format '%s'\n", format);
    } else {
        printf("FAILURE: Outputs do not match for format '%s'\n", format);
    }

    // 返り値（出力長さ）の比較
    if (std_return == ft_return) {
        printf("SUCCESS: Return values match (length = %d)\n", std_return);
    } else {
        printf("FAILURE: Return values do not match (std = %d, ft = %d)\n", std_return, ft_return);
    }

    fclose(std_file);
    fclose(ft_file);
    remove("std_out.txt");
    remove("ft_out.txt");
}
