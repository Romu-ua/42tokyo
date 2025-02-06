#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

// ヘルパー関数: 文字列を新しく確保して結合する
static char *ft_strjoin(char *s1, char *s2)
{
    size_t len1 = s1 ? strlen(s1) : 0;
    size_t len2 = s2 ? strlen(s2) : 0;
    char *new_str = malloc(len1 + len2 + 1);
    if (!new_str) return NULL;

    if (s1) strcpy(new_str, s1);
    if (s2) strcpy(new_str + len1, s2);

    free(s1); // 古いメモリを解放
    return new_str;
}

// ヘルパー関数: 改行を探す
static char *find_newline(char *buffer)
{
    while (*buffer) {
        if (*buffer == '\n')
            return buffer;
        buffer++;
    }
    return NULL;
}

// `get_next_line` の実装
char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1]; // 静的変数（前回の残りデータを保持）
    char *line = NULL;
    char *newline_pos;
    int read_bytes;

    while (1)
    {
        if (!buffer[0]) // buffer が空なら新しく `read()` する
        {
            read_bytes = read(fd, buffer, BUFFER_SIZE);
            if (read_bytes <= 0) return line; // EOFまたはエラー
            buffer[read_bytes] = '\0'; // 文字列終端
        }

        newline_pos = find_newline(buffer);
        if (newline_pos) // 改行が見つかった場合
        {
            *newline_pos = '\0'; // 改行を切る
            line = ft_strjoin(line, buffer);
            memmove(buffer, newline_pos + 1, strlen(newline_pos + 1) + 1); // buffer を更新
            return line; // 1行を返す
        }
        else
        {
            line = ft_strjoin(line, buffer);
            buffer[0] = '\0'; // buffer をクリアし、次回 read() する
        }
    }
}
