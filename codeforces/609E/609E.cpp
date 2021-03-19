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
/* dsu */
constexpr int _MAXN = 2e5;

int _parent[_MAXN + 1], _size[_MAXN + 1];

void _Init() noexcept
{
	for (int i = 1; i <= _MAXN; ++i)
		_parent[i] = i, _size[i] = 1;
}
int _Find(int x) noexcept
{
	return (x == _parent[x] ? x : x = _Find(_parent[x]));
}
bool _Union(int x, int y) noexcept
{
	x = _Find(x), y = _Find(y);

	if (x == y) return false;

	if (_size[y] > _size[x])
		swap(x, y);

	_parent[y] = x;
	_size[x] += _size[y];
	return true;
}
int64 _Getsize(int x) noexcept
{
	return _size[_Find(x)];
}

/* main code */
#include <map>
#include <set>
#include <vector>

using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
using tiiii = tuple<int64, int, int, int>;
using edge = tiiii;

constexpr int MAXN = 2e5;

int n, m;
enum { Wi, From, To, ID };
edge edges[MAXN + 1];
set<int> spannTree;
int64 spannTreeWi = 0;

vector<pii> G[MAXN + 1];
int depth[MAXN + 1];
int maxPath[MAXN + 1][32]{}, Father[MAXN + 1][32]{};
void dfs(int now, int fa = -1)
{
	for (int i = 1; i < 32; ++i)
	{
		Father[now][i] = Father[Father[now][i - 1]][i - 1];
		maxPath[now][i] = max(maxPath[now][i - 1], maxPath[Father[now][i - 1]][i - 1]);
	}

	for (auto node : G[now])
	{
		int to = node.first;
		int wi = node.second;

		if (to == fa) continue;

		Father[to][0] = now;
		maxPath[to][0] = wi;
		depth[to] = depth[now] + 1;

		dfs(to, now);
	}
}

int64 lca(int u, int v)
{
	if (depth[u] > depth[v]) swap(u, v);

	int tmp = depth[v] - depth[u];
	int64 res = 0;

	for (int i = 0; tmp; ++i, tmp >>= 1)
		if (tmp & 1) res = max(res, (int64)maxPath[v][i]), v = Father[v][i];

	if (u == v) return res;

	for (int j = 31; j >= 0 && u != v; --j)
		if (Father[u][j] != Father[v][j])
		{
			res = max({res, (int64)maxPath[u][j], (int64)maxPath[v][j]});

			u = Father[u][j];
			v = Father[v][j];
		}

	return max({ res, (int64)maxPath[u][0], (int64)maxPath[v][0] });
}

int64 Ans[MAXN + 1];
int main()
{
	_Init();

	scanf("%d %d", &n, &m);

	FOR(i, 1, m + 1)
	{
		int u, v;
		int64 w;
		scanf("%d %d %lld", &u, &v, &w);
		get<From>(edges[i]) = u;
		get<To>(edges[i]) = v;
		get<Wi>(edges[i]) = w;
		get<ID>(edges[i]) = i;
	}

	sort(edges + 1, edges + 1 + m);

	FOR(i, 1, m + 1)
	{
		int from = get<From>(edges[i]), to = get<To>(edges[i]);
		int64 wi = get<Wi>(edges[i]);

		if (_Union(from, to))
		{
			spannTreeWi += wi;
			spannTree.emplace(i);

			G[from].emplace_back(to, wi);
			G[to].emplace_back(from, wi);
		}
	}

	dfs(get<From>(edges[*spannTree.begin()]));

	FOR(i, 1, m + 1)
	{
		if (spannTree.find(i) != spannTree.end())
		{
			Ans[get<ID>(edges[i])] = spannTreeWi;
			continue;
		}

		Ans[get<ID>(edges[i])] = spannTreeWi + get<Wi>(edges[i]) - lca(get<From>(edges[i]), get<To>(edges[i]));
	}

	FOR(i, 1, m + 1)
		printf("%lld\n", Ans[i]);

	return 0;
}
