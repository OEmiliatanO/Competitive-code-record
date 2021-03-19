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
#include <deque>
#include <climits>

constexpr int MAXN = 1e6;

int n, k, arr[MAXN + 1];
int64 ans, dp[MAXN + 1];
deque<int> dq;

int main()
{
	scanf("%d %d", &n, &k);
	if (k > n) k = n;

	for (int i = 1; i <= n; ++i)
		scanf("%d", arr + i);

	dq.emplace_back(0);
	for (int i = 1; i <= n; ++i)
	{
		while (dq.size() && dq.front() < i - k) dq.pop_front();
		dp[i] = dp[dq.front()] + arr[i];
		while (dq.size() && dp[dq.back()] > dp[i]) dq.pop_back();
		dq.emplace_back(i);
	}

	ans = LLONG_MAX;
	for (int i = n - k + 1; i <= n; ++i)
		ans = min(ans, dp[i]);

	printf("%lld", ans);

	return 0;
}
