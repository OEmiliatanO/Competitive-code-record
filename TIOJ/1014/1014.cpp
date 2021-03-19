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
constexpr uint MAXN = 16;
uint dp[1 << MAXN][MAXN + 1], T[MAXN + 1], n, tmp, ans = UINT_MAX;

int main()
{
	scanf("%u", &n);
	for (int i = 0; i < n; ++i)
		scanf("%u", T + i);

	memset(dp, 0x7f, sizeof(uint) * (1 << MAXN) * (MAXN + 1));

	dp[0][0] = 1;
	for(int S = 1; S < (1 << n); ++S)
		for (int i = 0; i < n; ++i)
			if(S & (1 << i))
				for (int j = 0; j < n; ++j)
				{
					tmp = dp[S - (1 << i)][j] + abs(i - j);
					tmp = ceil((double)tmp / T[i]) * T[i];
					dp[S][i] = min(dp[S][i], tmp);
				}

	for (int i = 0; i < n; ++i)
		ans = min(ans, dp[(1 << n) - 1][i]);

	printf("%u", ans);

	return 0;
}
