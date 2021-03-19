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

constexpr int MAXN = 1e5;

int n;
int c[MAXN + 1];
vector<int> G[MAXN + 1];

int sz[MAXN + 1];
pii heavySon[MAXN + 1];
int colorCnt[MAXN + 1]{};
int64 ans[MAXN + 1];
int64 maxval = 0, maxcolorSum = 0;
bool vis[MAXN + 1]{};

void dfs(int now = 1, int from = -1)
{
	heavySon[now] = pii{-1, -1};
	sz[now] = 1;

	for (int nex : G[now])
	{
		if (nex == from) continue;

		dfs(nex, now);
		sz[now] += sz[nex];

		heavySon[now] = max(pii{ sz[nex], nex }, heavySon[now]);
	}
}

enum {CLR, SAVE};
void calc(int now, int from, int val)
{
	colorCnt[c[now]] += val;

	if (val == -1) vis[now] = false;

	if (colorCnt[c[now]] >= maxval)
	{
		if (colorCnt[c[now]] > maxval)
			maxval = colorCnt[c[now]], maxcolorSum = 0;
		maxcolorSum += c[now];
	}

	for (int nex : G[now])
	{
		if (nex == from || (vis[nex] && val != -1)) continue;
		
		calc(nex, now, val);
	}
}

void solve(int now = 1, int from = -1, bool state = SAVE)
{
	for (int nex : G[now])
	{
		if (nex == from) continue;
		if (heavySon[now].second != nex)
			solve(nex, now, CLR);
	}

	if (heavySon[now].second != -1)
	{
		solve(heavySon[now].second, now, SAVE);
		vis[heavySon[now].second] = true;
	}

	calc(now, from, 1);
	ans[now] = maxcolorSum;

	if (state == CLR)
	{
		calc(now, from, -1);
		maxcolorSum = maxval = 0;
	}

}

int main()
{
	scanf("%d", &n);

	FOR(i, 1, n + 1)
		scanf("%d", &c[i]);

	FOR(i, 0, n - 1)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	dfs();
	solve();

	FOR(i, 1, n + 1)
		printf("%lld ", ans[i]);

	return 0;
}
