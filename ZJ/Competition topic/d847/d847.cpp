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
#include <cassert>
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
auto lowerbit = [](int x) { return x & (-x); };
int BIT[1002]{};
void updata(int, int);
int presum(int);

using tiii = tuple<int, int, int>;
constexpr int MAXN = 10000;
int N, x, y, ans[MAXN + 1];
tiii pts[MAXN + 1];

int main()
{
	while (~scanf("%d", &N))
	{
		memset(BIT, 0, sizeof(int) * 1002);
		assert(N <= 10000);
		for (int i = 0; i < N; ++i)
		{
			scanf("%d %d", &x, &y);
			assert(x >= 1 && x <= 1000 && y >= 1 && y <= 1000);
			pts[i] = { x, y, i };
			assert(i < MAXN + 1);
		}
		sort(pts, pts + N, [](const tiii& lhs, const tiii& rhs) {
			if (get<0>(lhs) != get<0>(rhs)) return get<0>(lhs) < get<0>(rhs);
			return get<1>(lhs) < get<1>(rhs);
			});

		for (int i, l = 0, r = 1; r <= N; )
		{
			while (get<0>(pts[r - 1]) == get<0>(pts[r]) && r < N) ++r;
			--r;
			for (i = l; i <= r; ++i)
				ans[get<2>(pts[i])] = presum(get<1>(pts[i]) - 1);
			for (i = l; i <= r; ++i)
				updata(get<1>(pts[i]), 1);
			r += 2;
			l = r - 1;
		}

		for (int i = 0; i < N; ++i)
			printf("%d\n", ans[i]);
	}

	return 0;
}

void updata(int index, int x)
{
	assert(index >= 0);
	while (index <= 1001) BIT[index] += x, index += lowerbit(index);
}
int presum(int index)
{
	int res = 0;
	while (index > 0)
		res += BIT[index], index -= lowerbit(index);
	return res;
}
