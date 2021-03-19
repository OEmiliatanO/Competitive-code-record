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

pair<int64, int64> ans[13]{ {0, 0}, {0, 1}, {1, 2} };

int n, t;

int main()
{
	for (int i = 3; i <= 12; ++i)
	{
		ans[i].first = (i - 1) * (ans[i - 1].first + ans[i - 2].first);
		ans[i].second = ans[i - 1].second * i;
	}

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		printf("%lld/%lld\n", ans[n].first, ans[n].second);
	}

	return 0;
}
