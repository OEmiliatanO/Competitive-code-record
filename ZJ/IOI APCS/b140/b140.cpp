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
constexpr int MAXT = 1e3;
constexpr int MAXM = 1e2;

int T, M;
int dp[MAXT + 1];
int t[MAXM + 1], v[MAXM + 1];

int main()
{
	scanf("%d %d", &T, &M);

	for (int i = 0; i < M; ++i)
		scanf("%d %d", t + i, v + i);

	for (int i = 0; i < M; ++i)
	{
		for (int j = T; j >= t[i]; --j)
			dp[j] = max(dp[j], dp[j - t[i]] + v[i]);
	}

	printf("%d", dp[T]);

	return 0;
}
