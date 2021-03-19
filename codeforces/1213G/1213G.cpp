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
void _Union(int x, int y) noexcept
{
	x = _Find(x), y = _Find(y);

	if (x == y) return;

	if (_size[y] > _size[x])
		swap(x, y);

	_parent[y] = x;
	_size[x] += _size[y];
}
int64 _getSize(int x)
{
	return _size[_Find(x)];
}

/* main code */
constexpr int MAXN = 2e5;

using tiii = tuple<int, int, int>;
enum {W, V, U};

int n, m;

tiii edges[MAXN];
pii query[MAXN + 1];
uint64 ans[MAXN + 1]{};

int64 Cn2(int64 n)
{
	if (n == 0 || n == 1) return 0;
	return n * (n - 1) / 2;
}

int main()
{
	_Init();

	scanf("%d %d", &n, &m);

	for (int i = 1, v, u, w; i <= n - 1; ++i)
	{
		scanf("%d %d %d", &v, &u, &w);
		get<V>(edges[i]) = v;
		get<U>(edges[i]) = u;
		get<W>(edges[i]) = w;
	}
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d", &query[i].first);
		query[i].second = i;
	}

	sort(edges + 1, edges + n);
	sort(query + 1, query + 1 + m);

	int i = 1;
	for (int j = 1; i <= m; ++i, ans[query[i].second] = ans[query[i - 1].second])
		while (j <= n - 1 && get<W>(edges[j]) <= query[i].first)
		{
			int a = _Find(get<U>(edges[j])), b = _Find(get<V>(edges[j]));

			if (a != b)
			{
				ans[query[i].second] += Cn2(_getSize(a) + _getSize(b));
				ans[query[i].second] -= (Cn2(_getSize(a)) + Cn2(_getSize(b)));
				_Union(a, b);
			}
			++j;
		}
	++i;
	while (i <= m)
		ans[query[i].second] = ans[query[i - 1].second];

	for (int i = 1; i <= m; ++i)
		printf("%llu ", ans[i]);

	return 0;
}
