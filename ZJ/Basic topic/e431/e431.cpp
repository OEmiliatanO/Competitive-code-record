#pragma warning( disable : 4996 )
/*
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
*/
#pragma GCC optimize("O3")
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

int n, m, ans;
bool p[12][12];

void dfs(int now, int i, int j)
{
	p[i][j] = true;

	if (now == n * m)
	{
		++ans;
		p[i][j] = false;

		return;
	}

	for (int t = 0, ni, nj; t < 4; ++t)
	{
		ni = i + Dir4[t][0], nj = j + Dir4[t][1];

		if (ni >= 0 && ni < n && nj >= 0 && nj < m && !p[ni][nj])
			dfs(now + 1, ni, nj);
	}

	p[i][j] = false;
}

int main()
{
	while (~scanf("%d %d", &n, &m))
	{
		ans = 0;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				dfs(1, i, j);

		printf("%d\n", ans >> 1);
	}
	return 0;
}
