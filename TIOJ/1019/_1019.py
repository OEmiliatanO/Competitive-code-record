for T in range(int(input().strip())):
    ans = [None] * 1002
    arr = [int(x) for x in input().strip().split()]
    N = arr[0]
    arr[0] = arr[1]
    ans[0] = ans[1] = 0

    for i in range(2, N + 1):
        ans[i] = min(ans[i - 1] + abs(arr[i - 1] - arr[i]), ans[i - 2] + abs(arr[i - 2] - arr[i]))

    print(ans[N])