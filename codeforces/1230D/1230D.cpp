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
#include <unordered_map>

constexpr int MAXN = 7e3;
using pll = pair<int64, int64>;

int n;
int numsize = 0, nums[MAXN];
int64 ans = 0;
unordered_map<int64, int> checker;
pll arr[MAXN];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &arr[i].first);
		++checker[arr[i].first];
		if (checker[arr[i].first] == 2)
			nums[numsize++] = i;
	}
	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i].second);

	checker.clear();

	for (int i = 0; i < numsize; ++i)
		for (int j = 0; j < n; ++j)
			if ((arr[nums[i]].first | arr[j].first) == arr[nums[i]].first && !checker[j])
			{
				checker[j] = true;
				ans += arr[j].second;
			}

	printf("%lld", ans);

	return 0;
}
