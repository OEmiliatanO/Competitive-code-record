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
constexpr int MAXN = 30;

int n, ans, recong[MAXN + 1], inrecong[MAXN + 1];
bool absent[MAXN + 1];

int popcnt(int x) noexcept
{
	int res = 0;
	while (x)
		++res, x -= (x & (-x));
	return res;
}

int main()
{
	while (~scanf("%d", &n) && n)
	{
		ans = 0;
		memset(absent, false, MAXN + 1);
		memset(recong, 0, sizeof(int) * (MAXN + 1));
		memset(inrecong, 0, sizeof(int) * (MAXN + 1));
		
		for (int i = 1, x; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
			{
				scanf("%d", &x);
				if (i == j) continue;
				recong[i] |= (x << j);
				inrecong[i] |= ((!x) << j);
			}

		bool Ok;
		do
		{
			Ok = true;
			for (int i = 1, a, b; i <= n; ++i)
			{
				if (absent[i]) continue;

				a = popcnt(recong[i]);
				b = popcnt(inrecong[i]);

				if (a < 2 || b < 2)
				{
					absent[i] = true;
					Ok = false;

					for (int j = 1; j <= n; ++j)
					{
						if (recong[j] & (1 << i)) recong[j] ^= (1 << i);
						if (inrecong[j] & (1 << i)) inrecong[j] ^= (1 << i);
					}

					break;
				}
			}

		} while (!Ok);

		for (int i = 1; i <= n; ++i)
			ans += !absent[i];

		printf("%d\n", ans);
	}

	return 0;
}
