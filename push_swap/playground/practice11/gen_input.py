import random

# 生成する数の個数
num_count = 20

# 1〜100の範囲でランダムな数を生成
random_numbers = [str(random.randint(1, 100)) for _ in range(num_count)]

# 空白区切りで出力
print(" ".join(random_numbers))
