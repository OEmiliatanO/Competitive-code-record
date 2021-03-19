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
constexpr int MAXN = 2e5;

int t, len, last, ans;
char s[MAXN];

int main()
{
	scanf("%d", &t);

	while (t--)
	{
		scanf("%s", s);

		last = -1;
		ans = 0;
		len = strlen(s);

		for (int i = 0; i < len; ++i)
			if (s[i] == '1')
			{
				for (int j = i, x = 0; j < len && j < (i + 20); ++j)
				{
					x = (x << 1) + s[j] - '0';
					if (j - x + 1 <= last) break;
					++ans;
				}
				last = i;
			}

		printf("%d\n", ans);
	}

	return 0;
}
