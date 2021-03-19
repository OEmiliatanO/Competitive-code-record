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
#include <queue>

constexpr int MAXN = 2e5;
constexpr int INF = 0x7f7f7f7f;
int n;
vector<int> G[MAXN + 1];

pii farest;
int dis[2][MAXN + 1];
void bfs(int now = 1, int idx = 0)
{
	queue<int> qu;

	farest = {-1, -1};
	memset(dis[idx], INF, sizeof(int) * (MAXN + 1));

	qu.emplace(now);
	dis[idx][now] = 0;

	while (!qu.empty())
	{
		int now = qu.front(); qu.pop();
		for (auto nex : G[now])
		{
			if (dis[idx][nex] == INF)
			{
				dis[idx][nex] = dis[idx][now] + 1;
				farest = max(farest, { dis[idx][nex], nex });
				qu.emplace(nex);
			}
		}
	}

}

int main()
{
	scanf("%d", &n);
	FOR(i, 0, n - 1)
	{
		int u, v;
		scanf("%d %d", &u, &v);

		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	int a, b;
	int ans = 0;
	pii sum = {-1, -1};

	bfs();	   a = farest.second;
	bfs(a, 0); b = farest.second;
	bfs(b, 1);

	ans += farest.first;

	FOR(i, 1, n + 1)
	{
		if (i == a || i == b) continue;

		sum = max(sum, { dis[0][i] + dis[1][i], i});
	}

	printf("%d\n", (ans + sum.first) / 2);

	printf("%d %d %d", a, b, sum.second);

	return 0;
}
