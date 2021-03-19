#pragma warning( disable : 4996 )
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
/*
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
inline int convert(char ch) noexcept
{
	return (ch >= '0' && ch <= '9' ? ch - '0' : ch - 'A' + 10);
}

constexpr int MAXN = 17;
uint64 DP[MAXN][MAXN], ans;
char s[MAXN]{1};
uint len, Index = 0;

int main()
{
	while (~scanf("%s", s + 1))
	{
		memset(DP, 0, sizeof(uint64) * MAXN * MAXN);
		ans = 0;
		len = strlen(s) - 1;

		if (s[1] == '?')
			for (int i = 1; i <= len; ++i) DP[1][i] = 1;
		else
			DP[1][convert(s[1])] = 1;

		for (Index = 2; Index <= len; ++Index)
			if (s[Index] == '?')
			{
				for (int j = 1; j <= len; ++j)
					for (int k = 1; k <= len; ++k)
						if (abs(j - k) >= 2)
							DP[Index][j] += DP[Index - 1][k];
			}
			else
			{
				s[Index] = convert(s[Index]);
				for (int k = 1; k <= len; ++k)
					if (abs(s[Index] - k) >= 2)
						DP[Index][s[Index]] += DP[Index - 1][k];
			}

		for (int i = 1; i <= len; ++i)
			ans += DP[len][i];

		printf("%llu\n", ans);
	}
	return 0;
}
