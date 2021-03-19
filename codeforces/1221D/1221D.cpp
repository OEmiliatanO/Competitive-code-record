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
#include <climits>

constexpr int MAXN = 3e5;
constexpr int64 INF = 1e18 + 20;

int q, n;
int h[MAXN + 1], cost[MAXN + 1];
int64 dp[MAXN + 1][3];

int main()
{
	scanf("%d", &q);

	while (q--)
	{
		scanf("%d", &n);

		for (int i = 1; i <= n; ++i)
		{
			scanf("%d %d", h + i, cost + i);
			dp[i][0] = dp[i][1] = dp[i][2] = INF;
		}

		for (int i = 1; i <= n; ++i)
		{
			for(int j = 0; j < 3; ++j)
				for (int k = 0; k < 3; ++k)
				{
					if (h[i] + j != h[i - 1] + k)
						dp[i][j] = min(dp[i][j], dp[i - 1][k] + j * cost[i]);
				}
		}

		printf("%lld\n", min({ dp[n][0], dp[n][1], dp[n][2] }));

	}

	return 0;
}
