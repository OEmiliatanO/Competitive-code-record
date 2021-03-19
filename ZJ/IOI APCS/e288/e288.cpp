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
#include <unordered_set>
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
constexpr int _MAXN_Dijoint = 10000;
int _Parent[_MAXN_Dijoint], _Rank[_MAXN_Dijoint];
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
constexpr int MAXN = 500001;
int n, m;
char s[1001], ch;
int64 hash[MAXN], ans;
int64 max;
unordered_multiset<int64> uset;

int main()
{
	scanf("%d %d", &m, &n);
	getchar();

	::max = ((int64)1 << m) - 1;

	for (int i = 0; i < n; ++i)
	{
		while ((ch = getchar()) && ch != '\n')
		{
			if (ch >= 'A' && ch <= 'Z') ch -= 'A';
			else if (ch >= 'a' && ch <= 'z') ch -= 'a' - 26;

			if (m > ch)
				::hash[i] |= ((int64)1 << ch);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		ans += uset.count(::max - ::hash[i]);
		uset.emplace(::hash[i]);
	}

	printf("%lld", ans);

	return 0;
}
