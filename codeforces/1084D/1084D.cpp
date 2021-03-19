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
#include <vector>
#include <climits>

using pil = pair<int, int64>;

constexpr int MAXN = 3e5;

int n;
int64 W[MAXN + 1]{}, DP[MAXN + 1]{};
int64 ans = INT64_MIN;
vector<pil> G[MAXN + 1];

void dfs(int now, int fa = -1)
{
	int64 max1 = 0, max2 = 0, cost;
	int nex;
	for (auto it : G[now])
	{
		nex = it.first;
		cost = it.second;

		if (nex == fa)
			continue;

		dfs(nex, now);

		if (DP[nex] - cost >= max1)
		{
			max2 = max1;
			max1 = DP[nex] - cost;
		}
		else
			max2 = max(max2, DP[nex] - cost);
	}

	DP[now] = max1 + W[now];
	ans = max({ ans, max1 + max2 + W[now], DP[now] });
}

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf("%lld", W + i);

	for (int i = 1, u, v, c; i <= n - 1; ++i)
	{
		scanf("%d %d %d", &u, &v, &c);
		G[u].emplace_back(pil{ v, c });
		G[v].emplace_back(pil{ u, c });
	}

	dfs(1);

	printf("%lld", ans);

	return 0;
}
