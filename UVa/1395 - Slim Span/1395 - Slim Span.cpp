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

/* dsu */
constexpr int _MAXN = 101;

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
#include <vector>
#include <climits>

constexpr int MAXN = 100;

struct Edge
{
	int from, to, wi;
}edges[MAXN * MAXN];

int n, m, ans;

int main()
{
	while (~scanf("%d %d", &n, &m), n | m)
	{
		ans = INT_MAX;

		for (int i = 0; i < m; ++i)
			scanf("%d %d %d", &edges[i].from, &edges[i].to, &edges[i].wi);

		sort(edges, edges + m, [](const Edge& lhs, const Edge& rhs) { return lhs.wi < rhs.wi; });

		for (int i = 0; i < m; ++i)
		{
			_Init();
			int maxedge = -1, ecnt = 0;
			for (int k = i; k < m; ++k)
			{
				int u = edges[k].from, v = edges[k].to, w = edges[k].wi;
				if (_Find(u) != _Find(v))
				{
					_Union(u, v);
					maxedge = max(maxedge, w);
					++ecnt;
				}
			}
			if (ecnt == n - 1)
				ans = min(maxedge - edges[i].wi, ans);
			else
				break;
		}

		printf("%d\n", (ans == INT_MAX ? -1 : ans));

	}

	return 0;
}
