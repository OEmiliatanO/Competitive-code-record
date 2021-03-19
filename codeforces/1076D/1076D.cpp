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
using pil = pair<int, int64>;
using pli = pair<int64, int>;

auto Equal = [](double a, double b) { return fabs(a - b) < EPS; };

/* mods */

/* main code */
#include <vector>
#include <queue>

constexpr int MAXN = 3e5;
constexpr int MAXM = 3e5;

struct Edge
{
	int from, to;
	int64 wi;
}edges[MAXM + 1];

int n, m, k;

vector<int> G[MAXN + 1];
int64 dis[MAXN + 1];
int preEdge[MAXN + 1];
bool vis[MAXN + 1]{};
vector<int> ans;
void dij(int S = 1)
{
	priority_queue<pli, vector<pli>, greater<pli>> pq;
	memset(dis, 0x3f, sizeof(int64) * (MAXN + 1));

	dis[S] = 0;
	pq.emplace(0, S);

	while (!pq.empty() && ans.size() <= k)
	{
		int now = pq.top().second; pq.pop();

		if (vis[now]) continue;
		vis[now] = true;

		ans.emplace_back(preEdge[now]);

		for (int nex : G[now])
		{
			if (edges[nex].to == now) swap(edges[nex].to, edges[nex].from);
			if (dis[edges[nex].to] > dis[now] + edges[nex].wi)
			{
				dis[edges[nex].to] = dis[now] + edges[nex].wi;
				preEdge[edges[nex].to] = nex;
				pq.emplace(dis[edges[nex].to], edges[nex].to);
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);

	FOR(i, 1, m + 1)
	{
		scanf("%d %d %lld", &edges[i].from, &edges[i].to, &edges[i].wi);

		G[edges[i].from].emplace_back(i);
		G[edges[i].to].emplace_back(i);
	}

	dij();

	printf("%d\n", ans.size() - 1);
	FOR(i, 1, ans.size())
		printf("%d ", ans[i]);

	return 0;
}
