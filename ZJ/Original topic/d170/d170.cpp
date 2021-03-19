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

int main()
{
	scanf("%d", &n);

	while (n--)
	{
		pii pts[3];

		FOR(i, 0, 3) scanf("%d %d", &pts[i].first, &pts[i].second);

		int x1 = pts[1].first - pts[0].first;
		int y1 = pts[1].second - pts[0].second;

		int x2 = pts[2].first - pts[0].first;
		int y2 = pts[2].second - pts[0].second;

		if ((x1 * x2 + y1 * y2) == sqrt((x1 * x1 + y1 * y1) * (x2 * x2 + y2 * y2)))
		{
			if ((x1 * x1 + y1 * y1) < (x2 * x2 + y2 * y2))
				puts("父親大人!母親大人!我快到了！");
			else
				puts("該死的東西!竟敢想讓我死！");
		}
		else
			puts("父親大人!母親大人!我快到了！");
	}

	return 0;
}
