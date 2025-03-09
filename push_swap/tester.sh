#!/bin/bash

test_file="6_numbers.txt"

log_file="push_swap_test_results.log"
> "$log_file"

if [ ! -f "$test_file" ]; then
    echo "Error: Test case file '$test_file' not found!"
    exit 1
fi

while IFS= read -r ARG; do
    if [ -z "$ARG" ]; then
        continue
    fi

    result=$(./push_swap $ARG | ./checker_Mac $ARG)

    echo "Test case: $ARG -> Result: $result" | tee -a "$log_file"
done < "$test_file"

echo "Test results saved to $log_file"
