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
#define x first
#define y second

using pt = pair<int64, int64>;

pt pts[3][2];
int64 l, u, v, k, area = 0;

int main()
{
	for (int i = 0; i < 3; ++i)
		scanf("%lld %lld %lld %lld", &pts[i][0].x, &pts[i][0].y, &pts[i][1].x, &pts[i][1].y);

	l = max(pts[0][0].x, pts[1][0].x), u = min(pts[0][1].x, pts[1][1].x);
	v = max(pts[0][0].y, pts[1][0].y), k = min(pts[0][1].y, pts[1][1].y);

	if (!(u <= l || k <= v)) area += (u - l) * (k - v);

	l = max(pts[0][0].x, pts[2][0].x), u = min(pts[0][1].x, pts[2][1].x);
	v = max(pts[0][0].y, pts[2][0].y), k = min(pts[0][1].y, pts[2][1].y);

	if (!(u <= l || k <= v)) area += (u - l) * (k - v);

	l = max({ pts[0][0].x, pts[1][0].x, pts[2][0].x }), u = min({ pts[0][1].x, pts[1][1].x, pts[2][1].x });
	v = max({ pts[0][0].y, pts[1][0].y, pts[2][0].y }), k = min({ pts[0][1].y, pts[1][1].y, pts[2][1].y });

	if (!(u <= l || k <= v)) area -= (u - l) * (k - v);

	if (area == (pts[0][1].x - pts[0][0].x) * (pts[0][1].y - pts[0][0].y)) puts("NO");
	else puts("YES");

	return 0;
}
