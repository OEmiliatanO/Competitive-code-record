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
#include <cmath>
#include <climits>
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
constexpr int MAXN = 1e6;
int T, n;
int64 arr[MAXN + 1], m, cnt;
bool ans[MAXN + 1];

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		memset(ans, true, MAXN + 1);

		scanf("%d", &n);

		cnt = ans[0] = ans[n - 1] = false;
		
		m = INT64_MIN;
		for (int i = 0; i < n; ++i)
		{
			scanf("%lld", arr + i);
			m = max(m, arr[i]);
			if (i >= 1 && i <= n - 2 && arr[i] < m)
				ans[i] = false;
		}

		m = arr[n - 1];
		for (int i = n - 2; i > 0; --i)
		{
			if (arr[i] > m)
				ans[i] = false;
			m = min(m, arr[i]);
		}

		for (int i = 0; i < n; ++i)
			cnt += ans[i];

		printf("%lld\n", cnt);
	}

	return 0;
}
