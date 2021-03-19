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

/* exgcd  __X * a + __Y * b = gcd(a, b) */
int64 __X, __Y;
tuple<int64, int64, int64> exgcd(int64 a, int64 b) noexcept
{
	if (b == 0)
	{
		__X = 1;
		__Y = 0;
		return { __X, __Y, a };
	}
	int64 r = get<2>(exgcd(b, a % b));
	int64 tmp = __X;
	__X = __Y;
	__Y = tmp - a / b * __Y;
	return { __X, __Y, r };
}

/* main code */
constexpr int64 MAXN = 1e4;
constexpr int64 M = 10001;

int64 n, x[(MAXN + 1) * 2];
bool ok = false;
tuple<int64, int64, int64> tmp;

int main()
{
	scanf("%lld", &n);
	
	for (int i = 1; i <= 2 * n; i += 2)
		scanf("%lld", x + i);

	for (int64 a = 0, b, t, gcd, tmp; a <= MAXN && !ok; ++a)
	{
		::tmp = exgcd(a + 1, M);

		b = get<0>(::tmp);
		gcd = get<2>(::tmp);
		t = x[3] - a * a * x[1];

		if (t % gcd) continue;
		b = b * t / gcd;

		ok = true;
		for (int i = 2; i <= 2 * n; ++i)
		{
			tmp = (a * x[i - 1] + b) % M;

			if (i & 1 && x[i] != tmp)
			{
				ok = false;
				break;
			}

			x[i] = tmp;
		}
	}

	for (int i = 2; i <= 2 * n; i += 2)
		printf("%lld\n", x[i]);

	return 0;
}

/*
x1
x2 = (a * x1 + b) mod m
x3 = (a * x2 + b) mod m
x3 = (a * ((a * x1 + b) mod m) + b) mod m
   = (a * (a * x1 + b) + b) mod m
   = (a * a * x1 + a * b + b) mod m

x3 + m * T = a * a * x1 + (a + 1) * b
x3 - a * a * x1 = (a + 1) * b + m * (-T)  ->  _A * x + _B * y = gcd(_A, _B)
											  _A = a + 1, _B = m
											  x, y = b, -T = exgcd(_A, _B)

											  (_A * b) * K + (_B * -T) * K = gcd(_A, _B) * K = x3 - a * a * x1
											  _A * (b * K) + _B * (-T * K) = gcd(_A, _B) * K = x3 - a * a * x1 = t
*/

