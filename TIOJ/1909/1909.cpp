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
#include <stack>
#include <vector>
#include <iostream>

constexpr int MAXN = 1e6;

int n, h;
stack<pii, vector<pii>> dq;
pii tmp;

vector <int> G[MAXN + 1];
int64 Size[MAXN + 1], ans[MAXN + 1];

void dfs(int now = 1, int fa = -1)
{
	int64 ls = -1, rs = -1;
	Size[now] = 1;
	ans[now] = 0;

	for (auto nex : G[now])
	{
		if (nex == fa)
			continue;

		dfs(nex, now);
		Size[now] += Size[nex];

		if (ls == -1) ls = Size[nex];
		else rs = Size[nex];
	}

	if (G[now].size() == 3)
		ans[now] += (int64)ls * rs;
	ans[now] += (int64)n - 1;
	ans[now] += ((int64)n - Size[now]) * ((int64)Size[now] - 1);

	ans[now] <<= 1;

	return;
}

int main()
{
	ios_jazz;
	cin >> n;

	cin >> h;
	dq.emplace(h, 1);

	for (int i = 2; i <= n; ++i)
	{
		cin >> h;
		while (dq.size() && h > dq.top().first)
		{
			tmp = dq.top(); dq.pop();
			if (dq.empty() || h <= dq.top().first)
			{
				G[tmp.second].emplace_back(i);
				G[i].emplace_back(tmp.second);
			}
			else if (h > dq.top().first)
			{
				G[dq.top().second].emplace_back(tmp.second);
				G[tmp.second].emplace_back(dq.top().second);
			}
		}
		dq.emplace(h, i);
	}

	tmp = dq.top(); dq.pop();
	while (dq.size())
	{
		G[dq.top().second].emplace_back(tmp.second);
		G[tmp.second].emplace_back(dq.top().second);
		tmp = dq.top(); dq.pop();
	}

	dfs();

	int ansi = -1;
	int64 anssize = -1;

	for (int i = 1; i <= n; ++i)
		if (anssize < ans[i])
			ansi = i, anssize = ans[i];

	cout << anssize << ' ' << ansi << '\n';

	return 0;
}
