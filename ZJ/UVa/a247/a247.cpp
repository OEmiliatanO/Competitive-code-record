#pragma warning( disable : 4996 )
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
/*
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

using int16 = int_fast16_t;
using uint16 = uint_fast16_t;
using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using pii = pair<int32, int32>;

/* fast power */
auto pow_fast_2 = [](int32 b) -> int64 { return 1 << b; };

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

int gcd(int a, int b)
{
	return (b != 0 ? gcd(b, a % b) : a);
}

/* main code */
constexpr int MAXN = 1e6;
int n, p, Ansp[MAXN + 1]{}, AnsPair[MAXN + 1]{}, num[MAXN + 1];

int main()
{
	memset(num, 0x7f, sizeof(int) * (MAXN + 1));
	for (int i = 1; i < 1000; ++i)
		for (int j = i + 1; ; j += 2)
		{
			if (gcd(i, j) != 1) continue;

			int a = j * j - i * i, b = 2 * i * j, c = j * j + i * i;
			if (c > MAXN) break;

			AnsPair[c]++;

			for (int k = 1; c * k <= MAXN; ++k)
			{
				num[a * k] = min(num[a * k], c * k);
				num[b * k] = min(num[b * k], c * k);
				num[c * k] = min(num[c * k], c * k);
			}
		}

	for (int i = 1; i <= MAXN; ++i)
		if(num[i] <= MAXN)
			++Ansp[num[i]];

	for (int i = 1; i <= MAXN; ++i)
	{
		AnsPair[i] += AnsPair[i - 1];
		Ansp[i] += Ansp[i - 1];
	}

	while (~scanf("%d", &n))
		printf("%d %d\n", AnsPair[n], n - Ansp[n]);

	return 0;
}
