// P5431.cpp
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>

using namespace std;

using int64 = long long;

/* exgcd  __X * a + __Y * b = gcd(a, b) */
int64 exgcd(int64 a, int64 b, int64& __X, int64& __Y) noexcept
{
    if (b == 0)
    {
        __X = 1, __Y = 0;
        return a;
    }

    int64 r = exgcd(b, a % b, __Y, __X);
    __Y -= a / b * __X;
    return r;
}

constexpr int MAXN = 5e6;

int64 n, p, k;
int64 arr[MAXN + 1];
int64 suf[MAXN + 1], pre[MAXN + 1];

int main()
{
    scanf("%lld %lld %lld", &n, &p, &k);

    int64 pren_inver, tmp;
    int64 upper = 0;

    pre[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        pre[i] = pre[i - 1] * arr[i] % p;
    }

    suf[n + 1] = 1;
    for (int i = n; i; --i)
        suf[i] =  suf[i + 1] * arr[i] % p;

    exgcd(pre[n], p, pren_inver, tmp);
    pren_inver = (pren_inver % p + p) % p;

    tmp = 1;
    for (int i = 1; i <= n; ++i)
    {
        tmp = k * tmp % p;
        upper = (upper + pre[i - 1] * suf[i + 1] % p * tmp % p) % p;
    }

    printf("%lld\n", upper * pren_inver % p);

    return 0;
}
