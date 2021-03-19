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
constexpr int64 mod = 1000000007;

/* fast power */
template <typename T>
T pow_fast(T x, int64 b) noexcept
{
	T tmp = 1;
	while (b)
	{
		if (b & 0x1) tmp = x * tmp % mod;
		x = x * x % mod;
		b >>= 1;
	}
	return tmp;
}

/* main code */

int n;

int main()
{
	while (~scanf("%d", &n))
	{
		int sum = 0;
		int64 ans = 0;

		for (int i = 0, x; i < n; ++i)
		{
			scanf("%d", &x);
			sum |= x;
		}

		for (int i = 0; i < 32; ++i)
			if (sum & (1 << i))
				ans = (ans % mod + pow_fast<int64>(2, n - 1) * (1LL << i) % mod) % mod;
		
		printf("%lld\n", ans);
	}

	return 0;
}
