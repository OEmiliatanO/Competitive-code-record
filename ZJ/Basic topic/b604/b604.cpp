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
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#define ios_jazz ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

constexpr int Dir4[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
constexpr int Dir8[8][2] = { {-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 1} };
constexpr double EPS = 1e-9;
const double PI = acos(-1);

using int16 = int_fast16_t;
using uint16 = uint_fast16_t;
using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using pii = pair<int32, int32>;

template <typename T>
T pow_fast(T x, int64 b)
{
	T tmp = 1;
	while (b)
	{
		if (b & 0x1) tmp = x * tmp;
		x = x * x;
		b >>= 1;
	}
	return tmp;
}

typedef struct point
{
	point() noexcept = default;
	int x, y;
}pt;

constexpr int MAXN = 1e4;
int n, l, r;
bool flag;
pt pts[MAXN];
double Ox, Oy, X, Y;

int main()
{
	while (scanf("%d", &n) && n)
	{
		l = 0, r = n - 1;
		flag = true;
		for (int i = 0; i < n; ++i)
			scanf("%d %d", &pts[i].x, &pts[i].y);

		if (n & 1) { puts("no"); continue; }

		sort(pts, pts + n, [](const pt& lhs, const pt& rhs) noexcept
			{ return (lhs.x < rhs.x) || (lhs.x == rhs.x && lhs.y < rhs.y); });

		Ox = static_cast<double>((pts[n - 1].x + pts[0].x) * 0.5);
		Oy = static_cast<double>((pts[n - 1].y + pts[0].y) * 0.5);

		while (l < r && flag)
		{
			X = static_cast<double>((pts[l].x + pts[r].x) * 0.5);
			Y = static_cast<double>((pts[l].y + pts[r].y) * 0.5);
			if (fabs(X - Ox) > EPS || fabs(Y - Oy) > EPS)
				flag = false;
			++l, --r;
		}

		if (flag) puts("yes");
		else puts("no");
	}

	return 0;
}
