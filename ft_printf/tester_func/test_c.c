#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "../ft_printf/includes/ft_printf.h"

void test_c(void)
{
    int i;
    int stdout_backup;      // 標準出力のバックアップ
    int fd_printf, fd_ft_printf;
    char buffer_printf[256], buffer_ft_printf[256];

    // 標準出力のバックアップを作成
    stdout_backup = dup(STDOUT_FILENO);

    // ファイルを作成
    fd_printf = open("printf_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
    fd_ft_printf = open("ft_printf_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);

    if (fd_printf == -1 || fd_ft_printf == -1) {
        perror("Failed to open files");
        return;
    }

    i = 32;
    while (i < 127) {
        // 標準printfの出力をキャプチャ
        dup2(fd_printf, STDOUT_FILENO); // 標準出力をprintf_output.txtにリダイレクト
        printf("%c", i);
        fflush(stdout);                // バッファをフラッシュ

        // 自作ft_printfの出力をキャプチャ
        dup2(fd_ft_printf, STDOUT_FILENO); // 標準出力をft_printf_output.txtにリダイレクト
        ft_printf("%c", i);
        fflush(stdout);                    // バッファをフラッシュ

        // ファイルから出力を読み取って比較
        lseek(fd_printf, 0, SEEK_SET); // ファイルポインタを先頭に戻す
        lseek(fd_ft_printf, 0, SEEK_SET);

        read(fd_printf, buffer_printf, sizeof(buffer_printf));
        read(fd_ft_printf, buffer_ft_printf, sizeof(buffer_ft_printf));

        buffer_printf[strcspn(buffer_printf, "\n")] = '\0';
        buffer_ft_printf[strcspn(buffer_ft_printf, "\n")] = '\0';

        // 出力の比較
        if (strcmp(buffer_printf, buffer_ft_printf) != 0) {
            // 異なる場合はエラーを表示して終了
            printf("Error: %d is not equal\n", i);
            break;
        }

        // 次のループのためにファイルを空にする
        ftruncate(fd_printf, 0);
        ftruncate(fd_ft_printf, 0);

        i++;
    }

    // 標準出力を元に戻す
    dup2(stdout_backup, STDOUT_FILENO);
    close(stdout_backup);
    close(fd_printf);
    close(fd_ft_printf);

    if (i == 127)
        printf("All tests passed!\n");

    return;
}
