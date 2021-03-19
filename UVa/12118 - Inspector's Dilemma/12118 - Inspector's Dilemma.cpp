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

constexpr int MAXV = 1e3;

int V, E, T;
int connectcnt[MAXV + 1], odd[MAXV + 1];
int com, ans;
int kase = 1;

int main()
{
	while (~scanf("%d %d %d", &V, &E, &T), V | E | T)
	{
		memset(connectcnt, 0, sizeof(int) * (MAXV + 1));
		memset(odd, 0, sizeof(int) * (MAXV + 1));
		ans = 0;
		_Init();
		com = V;

		for (int i = 0, u, v; i < E; ++i)
		{
			scanf("%d %d", &u, &v);
			++connectcnt[u]; ++connectcnt[v];
			if (_Find(u) != _Find(v))
			{
				--com;
				_Union(u, v);
			}
		}

		for (int i = 1; i <= V; ++i)
			if (_Find(i) == i && _Getsize(i) == 1)
				--com;

		ans = E + (com > 0 ? com - 1 : 0);
		for (int i = 1; i <= V; ++i)
			if (connectcnt[i] & 1)
				++odd[_Find(i)];

		for (int i = 1; i <= V; ++i)
		{
			if (odd[i] >= 4)
				ans += odd[i] / 2 - 1;
		}

		printf("Case %d: %d\n", kase++, ans * T);

	}

	return 0;
}
