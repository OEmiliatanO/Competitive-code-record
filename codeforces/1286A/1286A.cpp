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

constexpr int MAXN = 100;

int n;
int a[MAXN + 1];
int dp[MAXN + 1][MAXN + 1][2];

int main()
{
	memset(dp, 0x3f, sizeof(int) * (MAXN + 1) * (MAXN + 1) * 2);

	scanf("%d", &n);

	FOR(i, 1, n + 1)
		scanf("%d", a + i);

	dp[0][0][0] = dp[0][0][1] = 0;
	FOR(i, 1, n + 1)
		FOR(j, 0, i + 1)
		{
			if ((a[i] & 1) == 1 || a[i] == 0) dp[i][j][1] = min(dp[i - 1][j][0] + 1, dp[i - 1][j][1]);
			if ((a[i] & 1) == 0) dp[i][j][0] = min(dp[i - 1][j - 1][1] + 1, dp[i - 1][j - 1][0]);
		}

	printf("%d\n", min(dp[n][n >> 1][0], dp[n][n >> 1][1]));

	return 0;
}
