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
#include <set>
#include <map>
#include <unordered_map>
#define ios_jazz ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

constexpr int Dir4[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
constexpr int Dir8[8][2] = { {-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 1} };
constexpr double EPS = 1e-13;
const double PI = acos(-1);

using int16 = int_fast16_t;
using uint16 = uint_fast16_t;
using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using pii = pair<int32, int32>;

template <typename T>
T pow_fast(T x, int64 b)
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

int n, wi[(const int)1 << 9], ans[(const int)1 << 9];
static auto twoPow = [](const int& n) { return 1 << n; };

int main()
{
	while (~scanf("%d", &n) && n)
	{
		memset(ans, 0, sizeof(int) * twoPow(n));
		for (int i = 0; i < twoPow(n); ++i)
			scanf("%d", wi + i);

		ans[0] = wi[0];
		for (int i = 0; i < (1 << n); ++i)
			for (int j = 0; j < n; ++j)
				ans[i ^ (1 << j)] = max(ans[i ^ (1 << j)], ans[i] + wi[i ^ (1 << j)]);

		printf("%d\n", ans[(1 << n) - 1]);
	}

	return 0;
}
