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

/* main code */
constexpr int MAXN = 17;
auto D = [](const pair<int, int>& a, const pair<int, int>& b) -> double { return sqrt((double)(a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second)); };

double dis[MAXN][MAXN], ans[1 << MAXN];
pair<int, int> position[MAXN];
int n, t = 1;
char s[21];

int main()
{
	while (~scanf("%d", &n) && n)
	{
		n <<= 1;
		for (int i = 0; i < n; ++i)
			scanf("%s %d %d", s, &position[i].first, &position[i].second);

		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				dis[j][i] = dis[i][j] = D(position[i], position[j]);

		for (int i = 1; i < (1 << n); ++i)
			ans[i] = (1 << 30);

		for (int k = 0; k < (1 << n); ++k)
			for (int i = n - 1; i >= 0; --i)
				if (k & (1 << i))
				{	
					for (int j = 0; j < i; ++j)
					{
						if (k & (1 << j) && dis[i][j] + ans[k ^ (1 << i) ^ (1 << j)] < ans[k])
							ans[k] = dis[i][j] + ans[k ^ (1 << i) ^ (1 << j)];
					}
					break;
				}

		printf("Case %d: %.2lf\n", t++, ans[(1 << n) - 1]);
	}
	return 0;
}
