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
constexpr int MAXN = 1e6;
constexpr int MAXM = 1e3;
int n, m, arr[MAXN + 1];
int dp[MAXM + 1][MAXM + 1]{};

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; arr[i] %= m, ++i) scanf("%d", arr + i);

	if (n >= m)
	{
		puts("YES");
		return 0;
	}

	for (int i = 1; i <= n; ++i)
	{
		dp[i][arr[i]] = true;
		for (int j = 0; j < m; ++j)
		{
			dp[i][(arr[i] + j) % m] |= dp[i - 1][j];
			dp[i][j] |= dp[i - 1][j];
		}
	}

	puts((dp[n][0] ? "YES" : "NO"));


	return 0;
}
