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
constexpr int M = 23 * 28 * 33;
int abW = get<0>(exgcd(23 * 28, 33));
int acW = get<0>(exgcd(23 * 33, 28));
int bcW = get<0>(exgcd(28 * 33, 23));
int p, e, i, d, x, t = 1;

int main()
{
	abW = (abW % 33 + 33) % 33;
	acW = (acW % 28 + 28) % 28;
	bcW = (bcW % 23 + 23) % 23;
	while (~scanf("%d %d %d %d", &p, &e, &i, &d) && p >= 0)
	{
		x = (p * (28 * 33) * bcW + e * (23 * 33) * acW + i * (23 * 28) * abW - d) % M;
		while (x <= 0) x += M;

		printf("Case %d: the next triple peak occurs in %d days.\n", t++, x);
	}

	return 0;
}
