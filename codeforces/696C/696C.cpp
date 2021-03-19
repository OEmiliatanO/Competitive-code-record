// 696C.cpp
#include <iostream>

using namespace std;

using int64 = long long;

constexpr int M = 1e9 + 7;

/* fast power */
template <typename T>
T pow_fast(T x, int64 b, int64 m) noexcept
{
	T tmp = 1;
	while (b)
	{
		if (b & 0x1) tmp = x % m * tmp % m;
		x = x % m * x % m;
		b >>= 1;
	}
	return tmp % m;
}

/* exgcd  __X * a + __Y * b = gcd(a, b) */
int64 X, Y;
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

int n;
int64 upper = 2, lower;

int main()
{
    bool even = false;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int64 x;
		cin >> x;
		upper = pow_fast(upper, x, M);

        even |= !(x & 1);
    }

    exgcd(2, M, X, Y);
    X = (X % M + M) % M;

    upper = upper % M * X % M;
    lower = upper;

    exgcd(3, M, X, Y);
    X = (X % M + M) % M;

    upper = (upper + (even ? 1 : -1)) % M * X % M;
    upper = (upper % M + M) % M;

    cout << upper << "/" << lower;

    return 0;
}