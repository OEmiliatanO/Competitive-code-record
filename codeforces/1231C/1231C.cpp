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

int arr[502][502];
int n, m, ans = 0;

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			scanf("%d", &arr[i][j]);
			ans += arr[i][j];
		}

	for(int i = n; i; --i)
		for (int j = m; j; --j)
			if (arr[i][j] == 0)
			{
				arr[i][j] = min(arr[i + 1][j], arr[i][j + 1]) - 1;
				ans += arr[i][j];
			}
			else
			{
				if ((i + 1 <= n && arr[i][j] >= arr[i + 1][j]) || (j + 1 <= m && arr[i][j] >= arr[i][j + 1]))
				{
					puts("-1");
					return 0;
				}
			}

	printf("%d", ans);

	return 0;
}
