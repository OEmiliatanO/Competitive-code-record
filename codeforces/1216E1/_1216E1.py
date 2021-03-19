import math

def digit_sum(n):
    num = [0]
    for i in range(1, n):
        num.append(num[i - 1] + len(str(i)))

    s = [0]
    for i in range(1, n):
        s.append(s[i - 1] + num[i])

    return num, s


def binary_search(target, array, lower, upper):
    hit = -1
    while lower < upper:
        mid = lower + (upper - lower) // 2

        if array[mid] == target:
            hit = mid
            break
        elif array[mid] < target:
            hit = mid + 1
            lower = mid + 1
        else:
            hit = mid
            upper = mid

    return hit

n = 599999
num, total = digit_sum(n)

for t in range(int(input().strip())):

    target = int(input().strip())
    index_in_total = binary_search(target, total, 0, n)
    rest = target - total[index_in_total - 1]
    index_in_num = binary_search(rest, num, 0, n)
    index = rest - num[index_in_num - 1]

    print(str(index_in_num)[index - 1])
