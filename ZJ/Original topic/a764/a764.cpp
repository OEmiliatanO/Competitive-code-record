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

using int16 = short;
using uint16 = unsigned short;
using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using pii = pair<int, int>;

/* main code */
#include <climits>

constexpr int MAXN = 400;
int64 dis[MAXN][MAXN], Fdis[MAXN][MAXN], ans = INT64_MAX, wi;
int N, M, u, v;

int main()
{

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			dis[i][j] = dis[j][i] = Fdis[i][j] = Fdis[j][i] = INT_MAX;

	for (int i = 0; i < M; ++i)
	{
		scanf("%d %d %lld", &u, &v, &wi);
		Fdis[u][v] = Fdis[v][u] = dis[u][v] = dis[v][u] = min(dis[u][v], wi);
	}

	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i < k; ++i)
			for (int j = 1; j < i; ++j)
				ans = min(ans, Fdis[i][j] + dis[i][k] + dis[j][k]);

		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				Fdis[i][j] = min(Fdis[i][j], Fdis[i][k] + Fdis[k][j]);
	}

	if (ans == INT64_MAX)
		puts("No solution.");
	else
		printf("%lld", ans);

	return 0;
}
