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

int n;
int64 ans1, ans2, cnt = 1;

int pre[MAXN + 1]{1};

int main()
{
	ans1 = ans2 = 0;

	scanf("%d", &n);

	for(int i = 1, x; i <= n; ++i)
	{ 
		scanf("%d", &x);
		pre[i] = pre[i - 1] * (x > 0 ? 1 : -1);
	}

	for (int i = 1; i <= n; ++i)
	{
		if (pre[i] > 0)
			ans1 += cnt++;
		else
			ans1 += i - cnt;
	}

	printf("%lld %lld", (int64)n * (n + 1) / 2 - ans1, ans1);

	return 0;
}
