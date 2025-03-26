tests=(
  "cat:wc"
  "cat:sort"
  "cat:uniq"
  "cat:grep foo"
  "grep foo:wc -l"
  "cut -f1 -d' ':sort"
  "sort:uniq -c"
  "echo a b c:cut -f2 -d' '"
  "echo a:tr a-z A-Z"
)


for test in "${tests[@]}"; do
  IFS=":" read -r cmd1 cmd2 <<< "$test"
  echo "Testing: $cmd1 | $cmd2"

  # 本家コマンド：infile を標準入力に使う
  < infile eval "$cmd1" | eval "$cmd2" > cmp

  # pipex で比較
  ./pipex infile "$cmd1" "$cmd2" outfile

  if diff -q cmp outfile > /dev/null; then
    echo "OK"
  else
    echo "KO"
    diff -u cmp outfile
  fi
done
