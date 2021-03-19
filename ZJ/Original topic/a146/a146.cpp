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

/* main code */
enum { Mini, Max };
constexpr int MAXN = 1e6 + 1;
int n, k, cnt;
int arr[MAXN], ans[2][MAXN];
deque<pii> maxdqu, minidqu;

int main()
{
	while (~scanf("%d %d", &n, &k))
	{
		if (k > n) k = n;
		cnt = 0;
		maxdqu.clear();
		minidqu.clear();
		for (int i = 0; i < n; ++i)
			scanf("%d", arr + i);

		for (int i = 0; i < k; ++i)
		{
			while (maxdqu.size() && maxdqu.back().first <= arr[i])
				maxdqu.pop_back();
			while (minidqu.size() && minidqu.back().first >= arr[i])
				minidqu.pop_back();

			maxdqu.emplace_back(pii{ arr[i], i });
			minidqu.emplace_back(pii{ arr[i], i });
		}
		ans[Mini][cnt] = minidqu.front().first;
		ans[Max][cnt++] = maxdqu.front().first;

		for (int i = k; i < n; ++i)
		{
			if (maxdqu.size() && maxdqu.front().second <= i - k)
				maxdqu.pop_front();
			if (minidqu.size() && minidqu.front().second <= i - k)
				minidqu.pop_front();
			
			while (maxdqu.size() && maxdqu.back().first <= arr[i])
				maxdqu.pop_back();
			while (minidqu.size() && minidqu.back().first >= arr[i])
				minidqu.pop_back();
			
			maxdqu.emplace_back(pii{ arr[i], i });
			minidqu.emplace_back(pii{ arr[i], i });

			ans[Mini][cnt] = minidqu.front().first;
			ans[Max][cnt++] = maxdqu.front().first;
		}

		for (int i = 0; i < cnt; ++i)
			printf("%d%c", ans[Mini][i], " \n"[i == cnt - 1]);
		for (int i = 0; i < cnt; ++i)
			printf("%d%c", ans[Max][i], " \n"[i == cnt - 1]);
	}

	return 0;
}

