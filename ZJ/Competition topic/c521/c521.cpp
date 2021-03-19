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

int n, m, k;
int64 ans = 0, arr[MAXN + 1];

int main()
{
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 1; i <= n; ++i)
		scanf("%lld", arr + i);

	int searchCnt = k * 2 + 1;
	int times = (n / searchCnt);

	if (searchCnt * times == n)
	{
		for (int i = k + 1; i <= n; i += k * 2 + 1)
			ans += arr[i];
		printf("%lld", ans);

		return 0;
	}
	else if (times == 0)
	{
		printf("%lld", arr[n / 2]);

		return 0;
	}

	while (n > searchCnt * times) ++times;

	int nowPos = searchCnt * times - k;

	int st = k + 1 - ((nowPos - n) < 0 ? 0 : (nowPos - n));

	for (; st <= n; st += k * 2 + 1)
		ans += arr[st];

	printf("%lld", ans);

	return 0;
}
