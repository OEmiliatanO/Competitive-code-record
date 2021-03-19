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
constexpr int MAXN = 9 * 4e4;

int n;
char s[MAXN + 10];
bool ans, G[55][55];

int main()
{
	while (~scanf("%d", &n) && getchar())
	{
		ans = false;
		memset(G, false, 55 * 55);

		for (int t = 0, u, v; t < n; ++t)
		{
			scanf("%s", s);
			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j)
				{
					if (i == j || s[i * 2] == '0' || s[j * 2] == '0') continue;

					u = (s[i * 2] - 'A' + 1) * 2 + (s[i * 2 + 1] == '+');
					v = ((s[j * 2] - 'A' + 1) * 2 + (s[j * 2 + 1] == '+')) ^ 1;

					G[u][v] = true;
				}
		}

		for (int i = 1; i < 54; ++i)
			for (int j = 1; j < 54; ++j)
				for (int k = 1; k < 54; ++k)
					G[i][j] |= G[i][k] & G[k][j];

		for (int i = 1; i < 54; ++i)
			ans |= G[i][i];

		puts((ans ? "unbounded" : "bounded"));
	}

	return 0;
}
/*
3
A+00A+A+ 00B+D+A- B-C+00C+
1
K+K-Q+Q-
*/