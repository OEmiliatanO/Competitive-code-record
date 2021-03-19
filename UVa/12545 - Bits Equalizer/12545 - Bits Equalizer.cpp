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

int t;
char from[102];
char to[102];

int convert(char from, char to)
{
	if (from == '?')
		return (to - '0') << 1 | (to - '0');
	return (from - '0') << 1 | (to - '0');
}

int main()
{
	scanf("%d", &t);
	FOR (kase, 1, t + 1)
	{
		int stateCnt[4]{};
		int ans = 0, tmp;

		scanf("%s", from);
		scanf("%s", to);

		for (int i = 0; from[i]; ++i)
			if (from[i] != to[i])
				++stateCnt[convert(from[i], to[i])];

		tmp = min(stateCnt[convert('1', '0')], stateCnt[convert('0', '1')]);
		ans += tmp, stateCnt[convert('1', '0')] -= tmp, stateCnt[convert('0', '1')] -= tmp;

		tmp = min(stateCnt[convert('1', '0')], stateCnt[convert('?', '1')]);
		ans += 2 * tmp, stateCnt[convert('1', '0')] -= tmp, stateCnt[convert('?', '1')] -= tmp;

		if (stateCnt[convert('1', '0')])
		{
			printf("Case %d: -1\n", kase);
			continue;
		}

		printf("Case %d: %d\n", kase, ans + stateCnt[convert('0', '1')] + stateCnt[convert('?', '1')] + stateCnt[convert('?', '0')]);
	}

	return 0;
}
