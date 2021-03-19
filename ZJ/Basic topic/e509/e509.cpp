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
constexpr int _MAXN = 2e4;

int _parent[_MAXN + 1];
int64 _size[_MAXN + 1];

void _Init() noexcept
{
	for (int i = 0; i <= _MAXN; ++i)
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
constexpr int MAXR = 5e4;
constexpr int MAXN = 2e4;
constexpr int BASECOST = 1e4;

using tiii = tuple<int, int, int>;
enum { D, V, U };

int K, N, M, R;
tiii relation[MAXR + 1];
int64 ans;

int main()
{
	scanf("%d", &K);
	while (K--)
	{
		_Init();
		ans = 0;

		scanf("%d %d %d", &N, &M, &R);

		for (int i = 1, u, v, d; i <= R; ++i)
		{
			scanf("%d %d %d", &u, &v, &d);
			get<U>(relation[i]) = u;
			get<V>(relation[i]) = v + N;
			get<D>(relation[i]) = -d;
		}

		sort(relation + 1, relation + 1 + R);

		for (int i = 1; i <= R; ++i)
		{
			int u =  _Find(get<U>(relation[i])), v = _Find(get<V>(relation[i]));
			if (u != v)
			{
				ans += get<D>(relation[i]);
				_Union(u, v);
			}
		}

		printf("%lld\n", ((int64)N + M) * BASECOST + ans);
	}

	return 0;
}
