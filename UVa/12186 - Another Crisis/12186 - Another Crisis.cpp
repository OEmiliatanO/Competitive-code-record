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
#include <vector>
#include <climits>

constexpr int MAXN = 1e5;

int N, T;
vector<int> G[MAXN + 1];

int DP(int now)
{
	if (G[now].size() == 0)
		return 1;

	int res = 0, r = (T * G[now].size() - 1) / 100 + 1;

	vector<int> arr;
	for (auto nex : G[now])
		arr.emplace_back(DP(nex));

	sort(arr.begin(), arr.end());

	for (int i = 0; i < r; ++i)
		res += arr[i];

	return res;
}

int main()
{
	while (~scanf("%d %d", &N, &T) && (N | T))
	{
		for (int i = 0; i <= N; ++i) G[i].clear();

		for (int i = 1, fa; i <= N; ++i)
		{
			scanf("%d", &fa);
			G[fa].emplace_back(i);
		}

		printf("%d\n", DP(0));
	}
	return 0;
}
