#pragma warning( disable : 4996 )
/*
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
*/
//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <tuple>
#define ios_jazz ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

using int16 = short;
using uint16 = unsigned short;
using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using pii = pair<int, int>;

/* exgcd  __X * a + __Y * b = gcd(a, b) */
int64 __X, __Y;
tuple<int64, int64, int64> exgcd(int64 a, int64 b) noexcept
{
	if (b == 0)
	{
		__X = 1;
		__Y = 0;
		return { __X, __Y, a };
	}
	int64 r = get<2>(exgcd(b, a % b));
	int64 tmp = __X;
	__X = __Y;
	__Y = tmp - a / b * __Y;
	return { __X, __Y, r };
}

/* main code */
constexpr int MAXN = 1e6;
constexpr int64 m = 1e9 + 7;

int64 ans = 1, inv, fact[MAXN + 2]{1};
int n;

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n + 1; ++i) fact[i] = (fact[i - 1] * i) % m;
	for (int i = n + 2; i <= 2 * n + 2; ++i) ans = (ans * i) % m;

	inv = get<0>(exgcd(fact[n + 1], m));
	inv = ((inv % m) + m) % m;

	printf("%lld\n", (ans * inv ) % m - 1);

	return 0;
}
