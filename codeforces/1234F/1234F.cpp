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

char s[MAXN + 2];
int len;
int ans, dp[1 << 20];

int main()
{
	scanf("%s", s + 1);

	len = strlen(s + 1);

	for (int i = 1, st; i <= len; ++i)
	{
		st = 0;
		for (int j = i; j <= len; ++j)
		{
			if (st & (1 << (s[j] - 'a')))
				break;

			st |= (1 << (s[j] - 'a'));
			dp[st] = j - i + 1;
		}
	}

	for (int i = 0; i < (1 << 20); ++i)
		for (int j = 0; j < 20; ++j)
			if (i & (1 << j))
				dp[i] = max(dp[i], dp[i ^ (1 << j)]);

	ans = 0;
	for (int i = 0; i < (1 << 20); ++i)
		ans = max(ans, dp[i] + dp[~i & ((1 << 20) - 1)]);

	printf("%d", ans);

	return 0;
}
