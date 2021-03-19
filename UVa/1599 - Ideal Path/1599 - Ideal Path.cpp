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
#include <queue>

constexpr int MAXN = 1e5, MAXM = 2e5;

int n, m;
vector<pii> G[MAXN + 1];

int dis[MAXN + 1];
void revbfs(int st)
{
	queue<int> qu;
	int now;

	memset(dis, 0, sizeof(int) * (MAXN + 1));
	dis[st] = 1;
	qu.emplace(st);

	while (qu.size())
	{
		now = qu.front(); qu.pop();
		for (auto nex : G[now])
		{
			if (!dis[nex.first])
			{
				dis[nex.first] = dis[now] + 1;
				qu.emplace(nex.first);
			}
		}
	}
}

int path[MAXN + 2];
int idx = 0;
bool vis[MAXN + 1];
void bfs(int st)
{
	vector<int> qu, nexqu;
	memset(vis, false, MAXN + 1);
	
	qu.emplace_back(st);

	for (int i = 0; i < dis[1] - 1; ++i)
	{
		int minway = 1e9 + 1;
		for (auto now : qu)
		{
			for (auto nex : G[now])
			{
				if (dis[nex.first] == dis[now] - 1)
					minway = min(minway, nex.second);
			}
		}
		path[idx++] = minway;

		for (auto now : qu)
		{
			for (auto nex : G[now])
			{
				if (dis[nex.first] == dis[now] - 1 && nex.second == minway && !vis[nex.first])
				{
					nexqu.emplace_back(nex.first);
					vis[nex.first] = true;
				}
			}
		}
		qu.swap(nexqu);
		nexqu.clear();
	}

}

int main()
{
	while (~scanf("%d %d", &n, &m))
	{
		idx = 0;
		for (int i = 0; i <= n; ++i)
			G[i].clear();

		for (int i = 0, u, v, c; i < m; ++i)
		{
			scanf("%d %d %d", &u, &v, &c);

			if (u == v) continue;

			G[u].emplace_back(v, c);
			G[v].emplace_back(u, c);
		}

		revbfs(n);
		bfs(1);

		printf("%d\n", idx);
		for (int i = 0; i < idx; ++i)
		{
			if (i) putchar(' ');
			printf("%d", path[i]);
		}
		puts("");
	}
	return 0;
}