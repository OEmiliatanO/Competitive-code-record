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

int64 __gcd(int64 a, int64 b)
{
	return (b == 0 ? a : __gcd(b, a % b));
}

int t;
int64 x_1, x_2, y_1, y_2, a, b, gcd;

int main()
{
	scanf("%d", &t);

	while (t--)
	{
		scanf("%lld %lld %lld %lld", &x_1, &y_1, &x_2, &y_2);

		if (x_1 > x_2)
		{
			swap(x_1, x_2);
			swap(y_1, y_2);
		}

		if (x_1 == x_2)
		{
			printf("%lld\n", abs(y_2 - y_1) + 1);
			continue;
		}

		a = x_2 - x_1;
		b = y_2 - y_1;

		gcd = __gcd(abs(a), abs(b));

		a /= gcd;

		printf("%lld\n", (int64)((x_2 - x_1) / (double)a) + 1);
	}

	return 0;
}
