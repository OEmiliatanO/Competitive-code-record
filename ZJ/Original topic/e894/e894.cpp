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

/* main code */

int64 n, m, c;

int64 f(int64 i, int64 j)
{
	return i * i + j * j + c * i + j;
}
bool check(int64 x)
{
	int64 place = 0;
	for (int i = 0; i < n; ++i)
	{
		int64 l = 0, r = n - 1;
		int64 mid, ans = 0;

		while (l <= r)
		{
			mid = (l + r) >> 1;
			if (f(i, mid) <= x)
			{
				ans = mid + 1;
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		place += ans;
		if (place >= m) return true;
	}
	return false;
}

int main()
{
	while (~scanf("%lld %lld", &n, &m))
	{
		c = n - 10000;
		int64 l = -c * c / 4 - 10000, r = max(n * n + n, n * n * 2 + n + c * n) + 10000;
		int64 mid, ans = -1;

		while (l <= r)
		{
			mid = (l + r) >> 1;
			if (check(mid))
			{
				ans = mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		printf("%lld\n", ans);

	}

	return 0;
}
