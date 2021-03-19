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
using pli = pair<int64, int>;

auto Equal = [](double a, double b) { return fabs(a - b) < EPS; };

/* mods */

/* main code */
#include <deque>

constexpr int MAXM = 300;
constexpr int MAXN = 15e4;

int n, m, d;
int64 a, b, t, lastT = 0;
int64 dp[2][MAXN + 1]{};
deque<pli> dq;

int main()
{
	scanf("%d %d %d", &n, &m, &d);

	FOR(i, 1, m + 1)
	{
		scanf("%lld %lld %lld", &a, &b, &t);

		int64 dt = t - lastT;
		dq = deque<pli>();

		for(int64 j = 1, ptr = 1; j <= n; ++j)
		{
			while (!dq.empty() && dq.back().second < j - dt * d)
				dq.pop_back();
			while (ptr <= n && ptr <= j + dt * d)
			{
				while (!dq.empty() && dp[!(i & 1)][ptr] > dq.front().first)
					dq.pop_front();
				dq.emplace_front(dp[!(i & 1)][ptr], ptr);
				++ptr;
			}

			dp[i & 1][j] = dq.back().first + b - abs(a - j);
		}
	}

	FOR(j, 1, n + 1)
		dp[m & 1][1] = max(dp[m & 1][1], dp[m & 1][j]);

	printf("%lld", dp[m & 1][1]);

	return 0;
}
