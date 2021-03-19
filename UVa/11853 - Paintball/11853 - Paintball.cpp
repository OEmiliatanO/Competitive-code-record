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
#define FOR(x, l, r) for (int x = (l); x < (r); ++x)

constexpr int MAXN = 1e3;

struct Circle
{
	double x, y, r;
};

Circle circles[MAXN + 1];
int n;
double Left, Right;
bool isreach, vis[MAXN + 1];

bool dfs(int now)
{
	vis[now] = true;

	double& x = circles[now].x, & y = circles[now].y, & r = circles[now].r;

	if (y - r <= 0.0) return false;
	if (x - r <= 0.0)
		Left = min(Left, y - sqrt(r * r - x * x));
	if (x + r >= 1000.0)
		Right = min(Right, y - sqrt(r * r - (1000 - x) * (1000 - x)));

	FOR(i, 0, n)
	{
		double& dx = circles[i].x, & dy = circles[i].y, & dr = circles[i].r;
		if (!vis[i] && (x - dx) * (x - dx) + (y - dy) * (y - dy) <= (r + dr) * (r + dr))
			if (!dfs(i)) return false;
	}

	return true;
}

int main()
{
	while (~scanf("%d", &n))
	{
		isreach = true;
		Left = Right = 1000.0;
		memset(vis, false, MAXN + 1);

		for_each(circles, circles + n, [](const Circle& x) { scanf("%lf %lf %lf", &x.x, &x.y, &x.r); });

		FOR(i, 0, n)
			if (!vis[i] && circles[i].y + circles[i].r >= 1000.0)
				isreach &= dfs(i);

		if (isreach)
			printf("0.00 %.2lf 1000.00 %.2lf\n", Left, Right);
		else
			puts("IMPOSSIBLE");
	}
	
	return 0;
}
