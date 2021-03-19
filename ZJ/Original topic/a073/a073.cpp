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
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#define ios_jazz ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

constexpr int Dir4[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
constexpr int Dir8[8][2] = { {-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 1} };
constexpr double EPS = 1e-13;
const double PI = acos(-1);

using int16 = int_fast16_t;
using uint16 = uint_fast16_t;
using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using pii = pair<int32, int32>;

template <typename T>
T pow_fast(T x, int64 b) noexcept
{
	T tmp = 1;
	while (b)
	{
		if (b & 0x1) tmp = x * tmp;
		x = x * x;
		b >>= 1;
	}
	return tmp;
}

constexpr int MAXN = 1e6 + 1, MAXM = 2e5 + 1, MAXQ = MAXM;
int parent[MAXN], Rank[MAXN];
int N, M, Q;
uint64 ans;

int Find(int x) noexcept
{
	return (x == parent[x] ? x : x = Find(parent[x]));
}

void Union(int x, int y) noexcept
{
	x = Find(x), y = Find(y);
	if (x == y) return;

	ans += static_cast<uint64>(Rank[x] * Rank[y]);
	if (Rank[x] > Rank[y])
		swap(x, y);
	parent[x] = y, Rank[y] += Rank[x];
}

typedef struct
{
	int x, y, wi;
}edge;
typedef struct
{
	int Qw, num;
}query;

int cnt;
uint64 QAns[MAXQ];
edge edges[MAXM];
query Query[MAXQ];

int main()
{
	while (~scanf("%d %d %d", &N, &M, &Q))
	{
		ans = cnt = 0;
		memset(QAns, 0, sizeof(int) * Q);
		for (int i = 0; i <= N; ++i)
			parent[i] = i, Rank[i] = 1;

		for (int i = 0; i < M; ++i)
			scanf("%d %d %d", &edges[i].x, &edges[i].y, &edges[i].wi);
		for (int i = 0; i < Q && scanf("%d", &Query[i].Qw); ++i)
			Query[i].num = i;

		sort(edges, edges + M, [](const edge& lhs, const edge& rhs) noexcept { return lhs.wi < rhs.wi; });
		sort(Query, Query + Q, [](const query& lhs, const query& rhs) noexcept { return lhs.Qw < rhs.Qw; });

		for (int i = 0; i < Q; ++i)
		{
			while (cnt < M && edges[cnt].wi <= Query[i].Qw)
				Union(edges[cnt].x, edges[cnt].y), ++cnt;
			QAns[Query[i].num] = ans;
		}
		for (int i = 0; i < Q; ++i)
			printf("%llu\n", QAns[i]);
	}

	return 0;
}
