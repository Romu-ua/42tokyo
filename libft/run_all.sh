#!/bin/bash

#実行するターゲットのリスト
TARGETS=("test_ft_isalpha" "test_ft_isdigit" "test_ft_isalnum" "test_ft_isascii" "test_ft_isprint" "test_ft_strlen"
		 "test_ft_memset" "test_ft_bzero")

for target in "${TARGETS[@]}"; do
    echo "Runnig $target..."
    ./$target
    echo "---------------------"
done
