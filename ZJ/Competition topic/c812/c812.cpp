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
#include <vector>

constexpr int MAXN = 5000;

int n, v, q;
vector<pii> G[MAXN + 1];
int dis[MAXN + 1];

int ans = 0;
void dfs(int now = v, int fa = -1)
{
	for (auto it : G[now])
	{
		int nex = it.first;
		int w = it.second;

		if (nex == fa) continue;

		dis[nex] = min(dis[now], w);
		dfs(nex, now);

		ans += (dis[nex] >= q);
	}
}

int main()
{
	scanf("%d %d %d", &n, &v, &q);

	FOR(i, 0, n - 1)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}

	memset(dis, 0x7f, sizeof(dis));

	dfs();

	printf("%d", ans);
	
	return 0;
}
