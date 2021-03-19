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

/* fast power */
int pow_fast(uint64 x, uint64 b, uint64 m) noexcept
{
	if (m == 1) return 0;

	uint64 tmp = 1;
	x %= m;

	while (b)
	{
		if (b & 0x1) tmp = x * tmp % m;
		x = x * x % m;
		b >>= 1;
	}

	return tmp % m;
}

/* main code */
constexpr int MAXN = 3500;

int F[MAXN];
int getLenth(int m)
{
	if (m == 1) return 1;

	F[0] = 0, F[1] = 1;
	for (int i = 2; ; ++i)
	{
		F[i] = (F[i - 1] + F[i - 2]) % m;
		if (F[i - 1] == 0 && F[i] == 1)
			return i - 1;
	}
}

int T;
uint64 a, b;
int m;

int main()
{
	scanf("%d", &T);

	while (T--)
	{
		scanf("%llu %llu %d", &a, &b, &m);

		printf("%d\n", F[pow_fast(a, b, getLenth(m))]);
	}

	return 0;
}
