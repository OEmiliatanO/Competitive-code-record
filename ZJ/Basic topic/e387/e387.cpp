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

constexpr int MAXN = 20;

double ans[1 << 20][MAXN];
double dis[20][20]{};
double pts[MAXN][2];
int n;

int main()
{
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%lf %lf", &pts[i][0], &pts[i][1]);
	}

	FOR(i, 0, n)
		FOR(j, i + 1, n)
			dis[j][i] = dis[i][j] = sqrt((pts[i][0] - pts[j][0]) * (pts[i][0] - pts[j][0]) + (pts[i][1] - pts[j][1]) * (pts[i][1] - pts[j][1]));

	FOR(i, 0, (1 << n))
	{
		fill(ans[i], ans[i] + MAXN, 1e9);
	}

	FOR(i, 0, n)
		ans[1 << i][i] = 0;

	FOR(S, 1, (1 << n))
		FOR(i, 0, n)
		{
			if ((S & (1 << i)) == 0)
				FOR(j, 0, n)
				{
					if (S & (1 << j))
						ans[S | (1 << i)][i] = min(ans[S | (1 << i)][i], ans[S][j] + dis[j][i]);
				}
		}

	FOR(i, 0, n)
		ans[(1 << n) - 1][0] = min(ans[(1 << n) - 1][0], ans[(1 << n) - 1][i]);

	printf("%.2lf", ans[(1 << n) - 1][0]);

	return 0;
}
