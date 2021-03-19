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
#include <vector>

constexpr int MAXN = 1e5;
constexpr int MOD = 998244353;

vector<int> G[MAXN + 1];
int64 size[MAXN + 1];
int t, a[MAXN + 1], n, m;
int64 ans;

void dfs(int now, int last)
{
	::size[now] = 1;

	for (auto nex : G[now])
	{
		if (nex == last) continue;
		dfs(nex, now);
		::size[now] += ::size[nex];
	}
}

int main()
{
	scanf("%d", &t);

	while (t--)
	{
		scanf("%d %d", &n, &m);

		ans = 0;
		for (int i = 0; i <= n; ++i)
			G[i].clear();

		for (int i = 0, u, v; i < n - 1; ++i)
		{
			scanf("%d %d", &u, &v);
			G[u].emplace_back(v);
			G[v].emplace_back(u);
		}

		for (int i = 1; i <= m; ++i)
			scanf("%d", a + i);

		dfs(1, -1);

		for (int i = 2; i <= n; ++i)
		{
			::size[i - 1] = ::size[i] * (n - ::size[i]);
		}

		sort(::size + 1, ::size + n);
		sort(a + 1, a + m + 1, greater<int>());

		for (int i = 1; i <= m; ++i)
			ans += a[i] % MOD * ::size[i] % MOD;

		printf("%lld\n", ans % MOD);

	}

	return 0;
}
