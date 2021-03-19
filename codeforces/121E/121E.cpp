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
constexpr int MAXN = 1e5;
constexpr int MAXNUM = 1e4;

int n, m, l, r, d;
char s[10];
int arr[MAXN + 1];
bool isLuckyNumber[MAXNUM + 1];

void dfs(int num)
{
	if (num > MAXNUM) return;

	isLuckyNumber[num] = true;

	dfs(num * 10 + 4);
	dfs(num * 10 + 7);
}

/* BIT */
auto lowbit = [](int x) noexcept { return x & (-x); };
int BIT[MAXN + 1];
int ask(int);
void add(int, int);

int main()
{
	dfs(4); dfs(7);

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n && scanf("%d", arr + i); ++i) if (isLuckyNumber[arr[i]]) add(i, 1);

	while (m--)
	{
		scanf("%s", s);
		if (s[0] == 'c')
		{
			scanf("%d %d", &l, &r);
			printf("%d\n", ask(r) - ask(l - 1));
		}
		else
		{
			scanf("%d %d %d", &l, &r, &d);
			for (int i = l; i <= r; ++i)
			{
				if (isLuckyNumber[arr[i]]) add(i, -1);
				arr[i] += d;
				if (isLuckyNumber[arr[i]]) add(i, 1);
			}
		}
	}

	return 0;
}

int ask(int pos)
{
	int res = 0;
	for (; pos; pos -= lowbit(pos)) res += BIT[pos];
	return res;
}

void add(int pos, int v)
{
	for (; pos <= MAXN; pos += lowbit(pos)) BIT[pos] += v;
}
