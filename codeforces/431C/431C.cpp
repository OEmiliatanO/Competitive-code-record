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
constexpr int MAXN = 100;
constexpr int64 mod = 1e9 + 7;

int n, k, d;
int64 DP[MAXN + 1]{}, badway[MAXN + 1]{};

int main()
{
	scanf("%d %d %d", &n, &k, &d);

	badway[0] = DP[0] = 1;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= min(k, i); ++j)
			DP[i] = (DP[i] + DP[i - j]) % mod;

		for (int j = 1; j <= min(d - 1, i); ++j)
			badway[i] = (badway[i] + badway[i - j]) % mod;
	}

	printf("%lld", ((DP[n] - badway[n]) % mod + mod) % mod);

	return 0;
}
