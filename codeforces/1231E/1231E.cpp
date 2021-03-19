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

int q, n, ans;
char s[101], t[101];

int main()
{
	scanf("%d", &q);

	while (q--)
	{
		scanf("%d", &n);
		scanf("%s", s + 1);
		scanf("%s", t + 1);

		ans = n;

		for (int i = 1; i <= n; ++i)
		{
			int k = i;
			for (int j = 1; j <= n && k <= n;)
			{
				while (j <= n && s[j] != t[k])
					++j;

				if (j <= n)
					++j, ++k;
			}
			ans = min(ans, n - (k - i));
		}

		sort(s + 1, s + 1 + n);
		sort(t + 1, t + 1 + n);

		if (strcmp(s + 1, t + 1) == 0)
			printf("%d\n", ans);
		else
			puts("-1");
	}

	return 0;
}
