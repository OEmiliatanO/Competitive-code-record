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

using int16 = short;
using uint16 = unsigned short;
using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using pii = pair<int, int>;

/* main code */
constexpr int MAXN = 7e5;
auto MOD = [](int x) noexcept { return (x - 1) % MAXN + 1; };

int n, DP[MAXN + 1]{};

int main()
{
	scanf("%d", &n);

	for (int turn = 1, x; turn <= n; ++turn)
	{
		scanf("%d", &x);

		for (int i = 1; i <= MAXN; ++i)
			if (DP[i] && DP[i] != turn)
			{
				int v = MOD(i + x);
				if(!DP[v]) DP[v] = turn;
			}
			else if (i == x) DP[x] = turn;
	}

	for (n = MAXN; !DP[n]; --n);

	printf("%d", n);

	return 0;
}
