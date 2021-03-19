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
#include <vector>
#include <queue>

#define maxn 100005
#define X first
#define Y second
using namespace std;
struct Node {
	long long dis;
	int pre, cur;

	Node() = default;

	Node(long long d, int p, int c) :
		dis(d), pre(p), cur(c) {}
	bool operator < (const Node& a) const {
		return dis > a.dis;
	}
};

vector<pair<int, long long>> G[maxn];
priority_queue<Node> pq;

int n;
Node tmp[6];

int main()
{
	scanf("%d", &n);
	for (int i = 1, u, v, d; i < n; i++)
	{
		scanf("%d %d %d", &u, &v, &d);
		G[u].emplace_back(v, d);
		G[v].emplace_back(u, d);
		pq.push(Node(d, u, v));
		pq.push(Node(d, v, u));
	}
	Node tmp(0, 0, 0);
	for (int i = 0; i < 10 * n; i++)
	{
		if (i % 10 == 9)
		{
			if (pq.size() > 900000)
			{
				printf("%lld\n", pq.top().dis);
				return 0;
			}
			if (pq.size()) printf("%lld ", pq.top().dis);
			else printf("-1 ");
		}
		
		if (pq.empty()) continue;

		tmp = pq.top(); pq.pop();
		
		for (auto y : G[tmp.cur])
		{
			if (y.X == tmp.pre) continue;

			pq.emplace(Node(tmp.dis + y.Y, tmp.cur, y.X));
		}
	}
	printf("\n");
	return 0;
}