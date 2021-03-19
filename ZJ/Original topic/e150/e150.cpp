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
#include <queue>
#include <vector>
#include <tuple>
#define ios_jazz ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

constexpr int Dir4[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
constexpr int Dir8[8][2] = { {-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 1} };
constexpr double EPS = 1e-10;
const double PI = acos(-1);

using int16 = int_fast16_t;
using uint16 = uint_fast16_t;
using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using pii = pair<int32, int32>;

/* fast power */
auto pow_fast_2 = [](int32 b) -> int64 { return (int64)1 << b; };

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

/* main code */
constexpr int MAXN = 1e5;
int N, M, R, P;

//BIT
auto lowerbit = [](int x) { return x & (-x); };
int64 BIT[MAXN]{};
void update(int, int);
int64 sum(int, int);

int main()
{
	N = 10;
	update(2, 10);
	update(6, 10);
	update(1, -10);
	printf("%lld", sum(2, 3));

	return 0;
}

void update(int index, int value)
{
	while (index <= N)
		BIT[index] = (BIT[index] + value) % P, index += lowerbit(index);
}
int64 sum(int l, int r)
{
	int64 result = 0;
	while (r > 0 || l > 0)
		result = result + BIT[r], result = result - BIT[l], l -= lowerbit(l), r -= lowerbit(r);
	return result;
}
