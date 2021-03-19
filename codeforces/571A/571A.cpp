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

constexpr int Dir4[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
constexpr int Dir8[8][2] = { {-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 1} };
constexpr double EPS = 1e-9;
const double PI = acos(-1);

using int16 = short;
using uint16 = unsigned short;
using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using pii = pair<int, int>;

/* main code */

int64 a, b, c, l, ans;

int64 count(int64 a, int64 b, int64 c)
{
	int64 res = 0;

	for (int64 x = max(0ll, b + c - a); x <= l; ++x)
	{
		int64 k = min(a + x - b - c, l - x);
		res += (k + 2) * (k + 1) / 2;
	}

	return res;
}

int main()
{
	scanf("%lld %lld %lld %lld", &a, &b, &c, &l);

	ans = (l + 3) * (l + 2) * (l + 1) / 6;

	ans -= count(a, b, c);
	ans -= count(b, a, c);
	ans -= count(c, a, b);

	printf("%lld", ans);

	return 0;
}
