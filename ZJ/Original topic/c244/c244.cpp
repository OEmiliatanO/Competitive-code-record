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
int T, kase = 1;
int64 N, s1, v1, s2, v2, ans, val;

int main()
{
	scanf("%d", &T);

	while (T--)
	{
		ans = -1;
		scanf("%lld %lld %lld %lld %lld", &N, &s1, &v1, &s2, &v2);

		if (N <= 5000 * s1)
			for (int i = 0; i * s1 <= N; ++i)
			{
				val = v1 * i + (N - i * s1) / s2 * v2;
				ans = max(val, ans);
			}
		else if (N <= 5000 * s2)
			for (int i = 0; i * s2 <= N; ++i)
			{
				val = v2 * i + (N - i * s2) / s1 * v1;
				ans = max(val, ans);
			}
		else if (s2 * v1 >= s1 * v2)
			for (int i = 0; i <= min(s1 - 1, N / s2); i++)
			{
				val = v2 * i + (N - i * s2) / s1 * v1;
				ans = max(ans, val);
			}
		else
			for (int i = 0; i <= min(s2 - 1, N / s1); i++)
			{
				val = v1 * i + (N - i * s1) / s2 * v2;
				ans = max(ans, val);
			}

		printf("Case #%d: %lld\n", kase++, ans);
	}


	return 0;
}