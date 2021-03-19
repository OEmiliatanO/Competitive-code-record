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
constexpr double EPS = 1e-10;
const double PI = acos(-1);
const double E = exp(1);

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

#define isZero(x) ((x) + EPS > 0 && (x) - EPS < 0)
int p, q, _r, s, t, u, cnt;
double x, l, r;

int main()
{
	while (~scanf("%d %d %d %d %d %d", &p, &q, &_r, &s, &t, &u))
	{
		cnt = 0;
		auto f = [](const double &g) {
			return static_cast<double>(::p * exp(-g) + ::q * sin(g) + ::_r * cos(g) + ::s * tan(g) + ::t * g * g + ::u);
		};
		l = 0.0, r = 1.0;
		double a = f(l), b = f(r), c;

		while (a * b <= 0 && !isZero(a) && !isZero(b) && cnt < 21)
		{
			x = (l + r) * 0.5, c = f(x);
			++cnt;

			if (a * c <= 0 || isZero(x))
				r = x;
			else
				l = x;
		}

		if (isZero(a))
			x = l;
		else if (isZero(b))
			x = r;
		else if (!cnt)
		{
			puts("No solution");
			continue;
		}
		printf("%.4f\n", x);
	}

	return 0;
}
