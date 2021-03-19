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

using int16 = short;
using uint16 = unsigned short;
using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using pii = pair<int, int>;

/* main code */
#include <vector>
#include <queue>

using edge = pii;

constexpr int MAXM = 5000;
constexpr int MAXN = 5000;

edge E[MAXM + 1];
vector<int> V[MAXN + 1];
bool isCycle = false, vis[MAXN + 1]{};
int n, m, fa[MAXN + 1]{};

void BFS()
{
	queue<int> qu;

	for (int i = 1; i <= n; ++i)
		if (fa[i] == 0)
		{
			qu.emplace(i);
			vis[i] = true;
		}

	while (qu.size())
	{
		int now = qu.front(); qu.pop();

		for (auto to : V[now])
		{
			--fa[to];

			if (fa[to] == 0)
			{
				qu.emplace(to);
				vis[to] = true;
			}
		}
	}

	for (int i = 1; i <= n && !isCycle; ++i)
		isCycle |= !vis[i];

}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1, u, v; i <= m; ++i)
	{
		scanf("%d %d", &u, &v);
		V[u].emplace_back(v);
		++fa[v];
		E[i] = { u, v };
	}

	BFS();

	puts((isCycle ? "2" : "1"));

	for (int i = 1; i <= m; ++i)
		if (isCycle && E[i].first > E[i].second)
			printf("2 ");
		else
			printf("1 ");

	return 0;
}
