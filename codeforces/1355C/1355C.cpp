// 1355C.cpp
#include <iostream>
#include <algorithm>

using namespace std;

constexpr int MAXN = 1e6;

int A, B, C, D;

int64_t arr[MAXN + 10];

int main()
{
    cin >> A >> B >> C >> D;

    for (int i = A; i <= B; ++i)
    {
        ++arr[i + B];
        --arr[i + C + 1];
    }

    for (int i = 1; i <= MAXN; ++i)
        arr[i] += arr[i - 1];

    for (int i = 1; i <= MAXN; ++i)
        arr[i] += arr[i - 1];

    int64_t ans = 0;

    for (int i = C; i <= D; ++i)
    {
        ans += (int64_t)arr[MAXN] - arr[i];
    }

    cout << ans;

    return 0;
}
