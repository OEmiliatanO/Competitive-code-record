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

/* main code */
#include <queue>

constexpr int MAXN = 1e5;

int64 N, K, A, ans = 0, X[MAXN + 1], C[MAXN + 1];
priority_queue< int64, vector<int64>, greater<int64> > pq;

int main()
{
	scanf("%lld %lld", &N, &K);
	
	for (int i = 1; i <= N; ++i)
		scanf("%lld", X + i);

	scanf("%lld", &A);

	for (int i = 1; i <= N; ++i)
		scanf("%lld", C + i);

	for (int i = 1; i <= N; ++i)
	{
		pq.emplace(C[i]);
		while (K < X[i] && pq.size())
		{
			ans += pq.top();
			pq.pop();
			K += A;
		}
		if (K < X[i])
		{
			puts("-1");
			return 0;
		}
	}

	printf("%lld", ans);

	return 0;
}
