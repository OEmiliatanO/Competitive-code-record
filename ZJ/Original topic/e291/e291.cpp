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
auto pow_fast_2 = [](uint b) -> int64 { return static_cast<int64>(1 << b); };

template <typename T>
T pow_fast(T x, int64 b) noexcept
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

/* Dijoint Set */
constexpr int _MAXN = 10000;
int _Parent[_MAXN], _Rank[_MAXN];
int _Find(int x) noexcept
{
	return (_Parent[x] == x ? x : x = _Find(_Parent[x]));
}
bool _Union(int x, int y) noexcept
{
	x = _Find(x), y = _Find(y);
	if (x == y) return false;
	if (_Rank[x] > _Rank[y]) swap(x, y);
	_Parent[x] = y, _Rank[y] += _Rank[x];
	return true;
}

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
constexpr int MAXN = 100000;
constexpr int MAXD = 30;

uint n, d, x;
bool matA[MAXN][MAXD], matB[MAXD][MAXN];
uint ans = 0, matX[MAXD]{}, matK[MAXN];

int main()
{
	scanf("%u %u", &n, &d);

	for(int i = 0; i < n && getchar(); ++i)
		for (int j = 0; j < d; ++j)
		{
			matA[i][j] = (getchar() - '0') & 1;
		}

	/*puts("A:");
	for (int i = 0; i < n; ++i, puts(""))
		for (int j = 0; j < d; ++j)
		{
			printf("%d ", matA[i][j]);
		}*/

	for (int j = 0; j < d; ++j)
		for (int i = 0; i < n; ++i)
			matB[j][i] = matA[i][j];

	/*puts("B:");
	for (int j = 0; j < d; ++j, puts(""))
		for (int i = 0; i < n; ++i)
			printf("%d ", matB[j][i]);*/

	for(int i = 0; i < d; ++i)
		for (int j = 0; j < n; ++j)
		{
			matX[i] += matA[j][i];
			puts("X:");
			for (int k = 0; k < d; ++k)
				printf("%d ", matX[k]);
			puts("");
		}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < d; ++j)
			matK[i] += matB[j][i] * matX[j];

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", matK[i]);
		ans += (n - matK[i]);
	}
	puts("");

	//ans -= n;
	//printf("%u", ans >> 1);

	return 0;
}
