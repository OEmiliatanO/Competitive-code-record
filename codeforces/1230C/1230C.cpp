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

int n, m, ans = -1;
bool G[8][8]{};

int main()
{
	scanf("%d %d", &n, &m);
	

	if (n <= 6)
	{
		printf("%d\n", m);
		return 0;
	}

	for (int i = 0, u, v; i < m; G[u][v] = G[v][u] = true, ++i)
		scanf("%d %d", &u, &v);

	for (int a = 1; a <= n; ++a)
		for (int b = a + 1, cnt; b <= n; ++b)
		{
			cnt = m;
			for (int k = 1; k <= n; ++k)
				cnt -= (G[a][k] && G[k][b]);

			ans = max(ans, cnt);
		}

	printf("%d", ans);

	return 0;
}
