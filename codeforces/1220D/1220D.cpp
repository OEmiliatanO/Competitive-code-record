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

int n, amount, iindex;
int t[65]{};
pair<int64, int> b[MAXN + 1];

int main()
{
	scanf("%d", &n);
	for (int i = 0, cnt; i < n; ++i)
	{
		scanf("%lld", &b[i].first);
		
		int64 tmp = b[i].first;
		cnt = 0;

		while ((tmp & 1) == 0)
			tmp >>= 1, ++cnt;

		++t[cnt];
		b[i].second = cnt;
	}

	amount = 0, iindex = -1;
	for (int i = 0; i <= 64; ++i)
		if (amount < t[i])
			amount = t[i], iindex = i;

	printf("%d\n", n - amount);
	for (int i = 0; i < n; ++i)
	{
		if (b[i].second != iindex)
			printf("%lld ", b[i].first);
	}

	return 0;
}
