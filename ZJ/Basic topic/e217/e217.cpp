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
auto pow_fast_2 = [](int64 b) -> int64 { return 1 << b; };

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
uint64 ans[50] = { 1, 1, 1, 2, 3, 5, 9, 18, 35, 75, 159, 355, 802, 1858, 4347, 10359, 24894, 60523, 148284, 366319, 910726, 2278658, 5731580, 14490245, 36797588, 93839412, 240215803, 617105614, 1590507121, 4111846763, 10660307791, 27711253769, 72214088660, 188626236139, 493782952902, 1295297588128, 3404490780161, 8964747474595, 23647478933969, 62481801147341, 165351455535782, 438242894769226, 1163169707886427, 3091461011836856, 8227162372221203, 21921834086683418, 58481806621987010, 156192366474590639, 417612400765382272, 1117743651746953270 };
int n;

int main()
{
	while (~scanf("%d", &n) && n)
		printf("%llu\n", ans[n - 1]);
	return 0;
}
