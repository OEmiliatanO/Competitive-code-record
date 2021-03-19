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
#include <climits>
#include <cmath>
#include <algorithm>
#include <tuple>
#define ios_jazz ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define FOR(i, l, r) for (int i = (l); i < (r); ++i)
#define FORR(i, r, l) for (int i =(r); i >= (l); --i)
#define P(STR) puts(#STR)

using namespace std;

constexpr int Dir4[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
constexpr int Dir8[8][2] = { {-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 1} };
constexpr double EPS = 1e-8;
const double PI = acos(-1);

using int16 = short;
using uint16 = unsigned short;
using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using pii = pair<int, int>;

auto Equal = [](double a, double b) { return fabs(a - b) < EPS; };

/* mods */
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

/* mul */
int64 mul(int64 a, int64 b, int64 m) noexcept
{
	int64 tmp = 0;
	while (b)
	{
		if (b & 0x1) tmp = (tmp % m + a % m) % m;
		a = (a % m + a % m) % m;
		b >>= 1;
	}
	return tmp % m;
}

/* fast power */
template <typename T>
T pow_fast(T x, int64 b, int64 m) noexcept
{
	T tmp = 1;
	while (b)
	{
		if (b & 0x1) tmp = mul(tmp, x, m);
		x = mul(x, x, m);
		b >>= 1;
	}
	return tmp % m;
}

/* main code */

int64 n, m, l;

int main()
{
	scanf("%lld %lld %lld", &n, &m, &l);

	int64 Mod = n + 1;
	int64 inv = get<0>(exgcd(2, n + 1));

	inv = (inv % Mod + Mod) % Mod;

	inv = pow_fast<int64>(inv, m, Mod);

	printf("%lld", mul(l, inv, Mod));

	return 0;
}
