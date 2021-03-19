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
int64 pow_fast(int64 x, int64 b, int64 M) noexcept
{
	int64 tmp = 1;
	while (b)
	{
		if (b & 0x1) tmp = (x % M * tmp % M) % M;
		x = (x % M * x % M) % M;
		b >>= 1;
	}
	return tmp % M;
}

/* main code */

constexpr int Mod = 998244353;

int n, pi;
int64 ans = 0, P;

int main()
{
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &pi);

		P = 100 * (pow_fast(pi, Mod - 2, Mod) % Mod) % Mod;
		ans = (ans + 1) * P % Mod;
	}

	printf("%lld", ans);

	return 0;
}
