// 1618 - Weak Key.cpp
#pragma warning( disable : 4996 )
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

constexpr int MAXN = 5000;

int T, n;
int arr[MAXN + 1];

int STval[MAXN + 1][20]{};
int STpos[MAXN + 1][20]{};
void init(bool reverse = false)
{
    int tmp[MAXN + 1];

    if (reverse)
        for (int i = 1; i <= n; ++i)
            arr[i] = n - arr[i] + 1;

    memcpy(tmp, arr, sizeof(int) * (MAXN + 1));
    memset(STval, 0, sizeof(int) * (MAXN + 1) * 20);
    memset(STpos, 0, sizeof(int) * (MAXN + 1) * 20);

    sort(tmp + 1, tmp + 1 + n);

    for (int i = 1; i <= n; ++i)
    {
        arr[i] = lower_bound(tmp + 1, tmp + 1 + n, arr[i]) - tmp;
        STval[i][0] = arr[i];
        STpos[arr[i]][0] = i;
    }

    for (int j = 1; (1 << j) <= n; ++j)
        for (int i = 1; i + (1 << j) <= n; ++i)
        {
            STval[i][j] = max(STval[i][j - 1], STval[i + (1 << (j - 1))][j - 1]);
            STpos[i][j] = max(STpos[i][j - 1], STpos[i + (1 << (j - 1))][j - 1]);
        }

}

int queryVal(int l, int r)
{
    int k = log2(r - l + 1);

    return max(STval[l][k], STval[r - (1 << k) + 1][k]);
}
int queryPos(int l, int r)
{
    int k = log2(r - l + 1);

    return max(STpos[l][k], STpos[r - (1 << k) + 1][k]);
}

bool check()
{
    for (int p = 1; p <= n; ++p)
        for (int r = p + 2; r <= n; ++r)
        {
            if (arr[p] <= arr[r] || p + 1 > r - 1) continue;
            int Np = arr[p];
            int Nq = queryVal(p + 1, r - 1);

            if (Nq <= Np || Np + 1 > Nq - 1) continue;
            int s = queryPos(Np + 1, Nq - 1);

            if (s <= r) continue;

            return true;
        }
    return false;
}

int main()
{
    bool Found;

    scanf("%d", &T);

    while (T--)
    {
        Found = false;

        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", arr + i);

        init(false);
        Found |= check();
        init(true);
        Found |= check();

        puts((Found ? "YES" : "NO"));
    }

    return 0;
}
