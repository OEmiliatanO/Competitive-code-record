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
constexpr int _MAXN = 1e3;

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
void _Union(int x, int y) noexcept
{
	x = _Find(x), y = _Find(y);

	if (x == y) return;

	if (_size[y] > _size[x])
		swap(x, y);

	_parent[y] = x;
	_size[x] += _size[y];
}
int64 _Getsize(int x) noexcept
{
	return _size[_Find(x)];
}

/* main code */
#include <climits>
#include <vector>

constexpr int MAXN = 1e3;

struct Net
{
	int N, W;
	int Citys[MAXN + 1];
}Packets[9];

struct Point
{
	int x, y;
	int Distance(const Point& a)
	{
		return (x - a.x) * (x - a.x) + (y - a.y) * (y - a.y);
	}
}City[MAXN + 1];

struct edge
{
	int from, to, wi;
	edge(int f, int t, int w) :from(f), to(t), wi(w) {}
};

int t, n, q, ans;
vector<int> spannEdges;
vector<edge> Edges;

int filter(int state)
{
	int ans = 0;
	for (int i = 0; state >> i; ++i)
	{
		if (((state >> i) & 1) == 0) continue;

		ans += Packets[i].W;
		for (int j = 2; j <= Packets[i].N; ++j)
			_Union(Packets[i].Citys[j], Packets[i].Citys[j - 1]);
	}

	for (auto e : spannEdges)
	{
		int u = _Find(Edges[e].from), v = _Find(Edges[e].to);
		if (u != v)
		{
			ans += Edges[e].wi;
			_Union(u, v);
		}
	}

	return ans;
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		Edges.clear();
		Edges.reserve(sizeof(double) * ((MAXN - 1) * MAXN) / 2);
		spannEdges.clear();
		
		ans = INT_MAX;

		scanf("%d %d", &n, &q);

		FOR(i, 0, q)
		{
			scanf("%d %d", &Packets[i].N, &Packets[i].W);
			FOR(j, 1, Packets[i].N + 1)
				scanf("%d", &Packets[i].Citys[j]);
		}

		FOR(i, 1, n + 1)
			scanf("%d %d", &City[i].x, &City[i].y);

		FOR(i, 1, n + 1)
			FOR(j, i + 1, n + 1)
				Edges.emplace_back(i, j, City[i].Distance(City[j]));

		sort(Edges.begin(), Edges.end(), [](const edge& lhs, const edge& rhs) { return lhs.wi < rhs.wi; });

		_Init();
		int id = 0;
		for (auto it : Edges)
		{
			if (_Find(it.from) != _Find(it.to))
			{
				spannEdges.emplace_back(id);
				_Union(it.from, it.to);
			}
			++id;
		}

		FOR(i, 0, 1 << q)
		{
			_Init();
			ans = min(ans, filter(i));
		}

		printf("%d\n", ans);
		if (t) puts("");

	}

	return 0;
}

