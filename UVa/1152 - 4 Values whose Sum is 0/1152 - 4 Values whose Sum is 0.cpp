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

int t, n, ans;

int Set[4][4000];
int composeAB[7998050];
int composeCD[7998050];

int main()
{
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < 4; ++j)
				scanf("%d", &Set[j][i]);

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
			{
				composeAB[i * n + j] = Set[0][i] + Set[1][j];
				composeCD[i * n + j] = Set[2][i] + Set[3][j];
			}

		sort(composeAB, composeAB + n * n);

		ans = 0;
		for (int i = 0; i < n * n; ++i)
			ans += upper_bound(composeAB, composeAB + n * n, -composeCD[i]) - lower_bound(composeAB, composeAB + n * n, -composeCD[i]);

		printf("%d\n", ans);

		if (t) puts("");
	}

	return 0;
}
