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
#include <climits>
#include <cmath>
#include <algorithm>
#include <tuple>
#define ios_jazz ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define FOR(i, l, r) for (int i = (l); i < (r); ++i)
#define FORR(i, r, l) for (int i =(r); i >= (l); --i)
#define P(STR) puts(#STR)

using namespace std;

constexpr int Dir4[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
constexpr int Dir8[8][2] = { {-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 1} };
constexpr double EPS = 1e-8;
const double PI = acos(-1);

using int16 = short;
using uint16 = unsigned short;
using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using pii = pair<int, int>;

auto Equal = [](double a, double b) { return fabs(a - b) < EPS; };

/* mods */

/* main code */

int n;
int arr[5000];
int64 frac[13]{ 1 };
int64 ans = 0;

void SwapInterval(int p1, int p2, int len)
{
	for (int i = 0; i < len; ++i)
		swap(arr[p1 + i], arr[p2 + i]);
}

bool isIncrease(int pos, int len)
{
	for (int i = 1; i < len; ++i)
		if (arr[pos + i - 1] + 1 != arr[pos + i])
			return false;
	return true;
}

void dfs(int range = 1, int step = 0)
{
	if (range > n)
	{
		ans += frac[step];
		return;
	}

	int pos1 = 0, pos2 = 0;
	for (int i = 1; i <= (1 << n); i += (1 << range))
	{
		if (!isIncrease(i, 1 << range))
			if (pos1 == 0) pos1 = i;
			else if (pos2 == 0) pos2 = i;
			else return;
	}

	int opRange = range - 1;

	if (!pos1 && !pos2)
		dfs(range + 1, step);
	else if (pos1 && !pos2)
	{
		SwapInterval(pos1, pos1 + (1 << opRange), 1 << opRange);
		dfs(range + 1, step + 1);
		SwapInterval(pos1, pos1 + (1 << opRange), 1 << opRange);
	}
	else
	{
		FOR(i, 0, 2)
			FOR(j, 0, 2)
			{
				SwapInterval(pos1 + i * (1 << opRange), pos2 + j * (1 << opRange), 1 << opRange);
				if (isIncrease(pos1, 1 << range) && isIncrease(pos2, 1 << range))
				{
					dfs(range + 1, step + 1);
				}
				SwapInterval(pos1 + i * (1 << opRange), pos2 + j * (1 << opRange), 1 << opRange);
			}
	}
}

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= (1 << n); ++i)
	{
		scanf("%d", arr + i);
	}

	for (int i = 1; i <= 12; ++i)
	{
		frac[i] = frac[i - 1] * i;
	}

	dfs();

	printf("%lld", ans);

	return 0;
}
