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
constexpr int MAXN = 2e5;

struct com
{
	int side[2][2]{};
	int ans[2]{};
}dp[MAXN + 1];

int N, A, B, x;

int main()
{
	scanf("%d %d %d", &N, &A, &B);

	scanf("%d", &x);

	dp[1].ans[0] = dp[1].ans[1] = 0;
	dp[1].side[0][0] = x;
	dp[1].side[0][1] = -1;
	dp[1].side[1][0] = -1;
	dp[1].side[1][1] = x;

	for (int i = 2, x; i <= N; ++i)
	{
		scanf("%d", &x);

		if (dp[i - 1].ans[0] > dp[i - 1].ans[1])
		{
			dp[i].ans[0] = dp[i].ans[1] = dp[i - 1].ans[0];
			dp[i].ans[0] += (dp[i - 1].side[0][0] == x ? A : (dp[i - 1].side[0][0] == -1 ? 0 : B));
			dp[i].ans[1] += (dp[i - 1].side[0][1] == x ? A : (dp[i - 1].side[0][1] == -1 ? 0 : B));

			dp[i].side[0][0] = x;
			dp[i].side[0][1] = dp[i - 1].side[0][1];
			dp[i].side[1][0] = dp[i - 1].side[0][0];
			dp[i].side[1][1] = x;
		}
		else
		{
			dp[i].ans[0] = dp[i].ans[1] = dp[i - 1].ans[1];
			dp[i].ans[0] += (dp[i - 1].side[1][0] == x ? A : (dp[i - 1].side[1][0] == -1 ? 0 : B));
			dp[i].ans[1] += (dp[i - 1].side[1][1] == x ? A : (dp[i - 1].side[1][1] == -1 ? 0 : B));

			dp[i].side[0][0] = x;
			dp[i].side[0][1] = dp[i - 1].side[1][1];
			dp[i].side[1][0] = dp[i - 1].side[1][0];
			dp[i].side[1][1] = x;
		}
	}

	printf("%d", max(dp[N].ans[0], dp[N].ans[1]));

	return 0;
}
