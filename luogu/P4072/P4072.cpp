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

constexpr int MAXN = 3e3;

int n, m;
int64 c[MAXN + 1];
int64 dp[2][MAXN + 1]{};
int64 S[MAXN + 1]{ 0 };

int q[MAXN + 1];
int l = 0, r = 0;

int64 slope_upper(int idx, int j, int i)
{
	return (dp[idx][i] + S[i] * S[i]) - (dp[idx][j] + S[j] * S[j]);
}
int64 slope_lower(int idx, int j, int i)
{
	return S[i] - S[j];
}
double slope(int idx, int j, int i)
{
	return (double)slope_upper(idx, j, i) / (double)slope_lower(idx, j, i);
}

int main()
{
	scanf("%d %d", &n, &m);

	FOR(i, 1, n + 1)
	{
		scanf("%lld", c + i);
		S[i] = S[i - 1] + c[i];
	}

	fill(dp[0] + 1, dp[0] + 1 + n, INT_MAX);
	for (int i = 1; i <= m; ++i)
	{
		bool idx = (i & 1);
		l = r = 0;
		q[r++] = 0;

		for (int j = 1; j <= n; ++j)
		{
			while (l + 1 < r && slope(!idx, q[l], q[l + 1]) < 2 * S[j])
				++l;

			dp[idx][j] = dp[!idx][q[l]] + (S[j] - S[q[l]]) * (S[j] - S[q[l]]);

			while (l + 1 < r && slope(!idx, q[r - 2], q[r - 1]) > slope(!idx, q[r - 1], j))
				--r;

			q[r++] = j;
		}
	}

	printf("%lld", m * dp[m & 1][n] - S[n] * S[n]);

	return 0;
}
