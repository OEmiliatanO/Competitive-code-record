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

constexpr int MAXN = 1e4;

using Point = pair<double, double>;
using Vector = Point;

int n;
Point pts[MAXN + 2];
Point ans[MAXN + 2];

double Cross(Vector a, Vector b)
{
	return a.first * b.second - a.second * b.first;
}

double distance(const Point& a, const Point& b)
{
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

bool cmp(const Point& a, const Point& b)
{
	double Cros = Cross({ a.first - pts[1].first, a.second - pts[1].second }, { b.first - pts[1].first, b.second - pts[1].second });

	if (Cros > 0)
		return true;

	if (Cros == 0 && distance(pts[0], a) < distance(pts[0], b))
		return true;

	return false;
}

int main()
{
	scanf("%d", &n);

	scanf("%lf %lf", &pts[1].first, &pts[1].second);
	for (int i = 2; i <= n; ++i)
	{
		scanf("%lf %lf", &pts[i].first, &pts[i].second);
		if (pts[i].second < pts[1].second)
			swap(pts[i], pts[1]);
	}

	sort(pts + 2, pts + 1 + n, cmp);

	ans[1] = pts[1];

	int cnt = 1;
	for (int i = 2; i <= n; ++i)
	{
		while (cnt > 1 && Cross({ ans[cnt].first - ans[cnt - 1].first, ans[cnt].second - ans[cnt - 1].second }, { pts[i].first - ans[cnt].first, pts[i].second - ans[cnt].second }) <= 0)
			--cnt;
		++cnt;
		ans[cnt] = pts[i];
	}

	ans[cnt + 1] = pts[1];

	double dis = 0;
	for (int i = 1; i <= cnt; ++i)
		dis += distance(ans[i], ans[i + 1]);

	printf("%.2lf\n", dis);

	return 0;
}
