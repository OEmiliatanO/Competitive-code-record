// a813.cpp
#pragma warning( disable : 4996 )
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

using int64 = long long;

constexpr int MAXN = 1e6;

int n;
int arr[MAXN + 10];
int dq[MAXN + 10];
int head, tail;
int64 ans = 0;

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d", arr + i);

    head = tail = n + 1;
    for (int i = n; i; --i)
    {
        int pos = upper_bound(dq + head, dq + tail, arr[i]) - dq;
        int pos2 = lower_bound(dq + head, dq + pos, arr[i]) - dq;
        
        if (!(pos == tail && tail - head == 0))
        {
            ans += min(tail - head, pos - head + 1) * 2LL;
            head = pos2;
        }

        dq[--head] = arr[i];
    }

    printf("%lld", ans);

    return 0;
}