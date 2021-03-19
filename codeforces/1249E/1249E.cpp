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

int n, c;
int a[MAXN + 1]{}, b[MAXN + 1]{};
int64 DP[MAXN + 1][2]{};

int main()
{
	scanf("%d %d", &n, &c);
	for (int i = 1; i <= n - 1; ++i) scanf("%d", a + i);
	for (int i = 1; i <= n - 1; ++i) scanf("%d", b + i);

	DP[1][0] = c, DP[1][1] = 0;
	for (int i = 2; i <= n; ++i)
	{
		DP[i][0] = min(DP[i - 1][0] + b[i - 1], DP[i - 1][1] + c + b[i - 1]);
		DP[i][1] = min(DP[i - 1][0] + a[i - 1], DP[i - 1][1] + a[i - 1]);
	}

	for(int i = 1; i <= n; ++i)
		printf("%lld ", min(DP[i][0], DP[i][1]));

	return 0;
}
