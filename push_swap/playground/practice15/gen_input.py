import random

def generate_unique_sequence(int_min, int_max,count=500):
    if count > int_max:
        raise ValueError("count must be less than or equal to int_max")

    numbers = random.sample(range(int_min, int_max + 1), count)
    return " ".join(map(str, numbers))

# 使用例
int_max = 2147483647 # 任意の最大値を指定
int_min = -2147483648
print(generate_unique_sequence(int_min, int_max))
