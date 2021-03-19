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
#include <map>
constexpr int MAXN = 1200000;

int t, sum, maxi;
char s[MAXN];
map<int64, int> Map;

void dfs(int l = 0, int r = strlen(s) - 1, int depth = 0)
{
	if (s[l] == '[')
	{
		int stack = 0;
		for (int splitpos = l + 1; splitpos <= r - 1; ++splitpos)
		{
			if (s[splitpos] == '[')
				++stack;
			else if (s[splitpos] == ']')
				--stack;

			if (stack == 0 && s[splitpos] == ',')
			{
				dfs(l + 1, splitpos - 1, depth + 1);
				dfs(splitpos + 1, r - 1, depth + 1);
			}
		}
	}
	else
	{
		int64 num = 0;
		for (int i = l; i <= r; ++i)
			num = num * 10 + s[i] - '0';
		++Map[num << depth];
	}
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", s);
		Map.clear();
		maxi = sum = 0;

		dfs();


		for (auto it : Map)
		{
			sum += it.second;
			maxi = max(it.second, maxi);
		}

		printf("%d\n", sum - maxi);
	}

	return 0;
}
