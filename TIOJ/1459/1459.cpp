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
#include <cassert>
using tlll = tuple<int64, int64, int64>;

tlll tmp;
int n, f[41], w[41];
bool ok;
int hr, mie;

int main()
{
	while (~scanf("%d", &n), n)
	{
		ok = true;
		hr = 12, mie = 0;
		W = 1;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d %d", f + i, w + i);
		}

		int64 m = w[0], ans = f[0] % w[0];

		for (int i = 1; i < n; ++i)
		{
			tmp = exgcd(m, w[i]);
			ans += (m * -get<0>(tmp)) * (ans - (f[i] % w[i])) / get<2>(tmp);
			m = m / get<2>(tmp) * w[i];
			ans = (ans % m + m) % m;
		}

		for (int i = 0; i < n; ++i)
			if ((ans - f[i]) % w[i] != 0)
			{
				ok = false;
				break;
			}

		if (!ok)
		{
			puts("Starvation");
		}
		else
		{
			mie += ans;
			hr += ans / 60, mie %= 60;
			hr %= 12;
			printf("%d:%02d\n", (hr == 0 ? 12 : hr), mie);
		}

	}

	return 0;
}
