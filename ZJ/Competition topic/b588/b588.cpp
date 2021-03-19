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
constexpr int Undefine = -1;
int x, y, z;
int ans[101][101][101];
bool dfs(int a, int b, int c)
{
	if (a == 0 && b == 0 && c == 0)
		return false;

	int arr[] = { a, b, c };
	sort(arr, arr + 3);

	swap(arr[0], a); swap(arr[1], b); swap(arr[2], c);

	if (ans[a][b][c] != Undefine) return ans[a][b][c];

	ans[a][b][c] = false;
	
	for (int i = a; i > 0; --i)
		ans[a][b][c] |= !dfs(a - i, b, c);
	for (int i = b; i > 0; --i)
		ans[a][b][c] |= !dfs(a , b - i, c);
	for (int i = c; i > 0; --i)
		ans[a][b][c] |= !dfs(a , b, c - i);

	for (int i = min(a, b); i > 0; --i)
		ans[a][b][c] |= !dfs(a - i, b - i, c);
	for (int i = min(b, c); i > 0; --i)
		ans[a][b][c] |= !dfs(a, b - i, c - i);
	for (int i = min(a, c); i > 0; --i)
		ans[a][b][c] |= !dfs(a - i, b, c - i);

	for (int i = min(min(a, b), c); i > 0; --i)
		ans[a][b][c] |= !dfs(a - i, b - i, c - i);

	return ans[a][b][c];
}

int main()
{
	memset(ans, Undefine, sizeof(int) * 101 * 101 * 101);
	
	while (scanf("%d %d %d", &x, &y, &z) == 3)
	{
		putchar((dfs(x, y, z) ? 'w' : 'l'));
		putchar('\n');
	}
	return 0;
}
