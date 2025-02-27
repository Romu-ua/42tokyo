import random

def generate_unique_sequence(int_max, count=50):
    if count > int_max:
        raise ValueError("count must be less than or equal to int_max")

    numbers = random.sample(range(1, int_max + 1), count)
    return " ".join(map(str, numbers))

# 使用例
int_max = 214748364711111  # 任意の最大値を指定
print(generate_unique_sequence(int_max))
