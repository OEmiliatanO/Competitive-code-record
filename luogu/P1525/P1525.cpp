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
constexpr int _MAXN = 2e4;

int _parent[_MAXN + 1], _size[_MAXN + 1];

void _Init() noexcept
{
	for (int i = 0; i <= _MAXN; ++i)
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

using tiii = tuple<int, int, int>;

constexpr int MAXN = 1e5;

enum { C, X, Y };
int n, m;
tiii edges[MAXN + 1];
int enemy[MAXN + 1]{};

int main()
{
	_Init();

	scanf("%d %d", &n, &m);

	FOR(i, 1, m + 1)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edges[i] = { c, a, b };
	}

	sort(edges + 1, edges + 1 + m, greater<tiii>());

	FOR(i, 1, m + 1)
	{
		int x = get<X>(edges[i]), y = get<Y>(edges[i]), c = get<C>(edges[i]);
		if (_Find(x) == _Find(y))
		{
			printf("%d", c);
			return 0;
		}

		if (!enemy[x]) enemy[x] = y;
		else _Union(enemy[x], y);

		swap(x, y);
		if (!enemy[x]) enemy[x] = y;
		else _Union(enemy[x], y);
	}

	puts("0");

	return 0;
}
