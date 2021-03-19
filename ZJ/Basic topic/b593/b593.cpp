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

char s[29];
int len;
uint64 C[27][27]{1};
uint64 ans;

int main()
{
	for (int i = 1; i <= 26; ++i)
		C[i][i] = C[i][0] = 1, C[i][1] = i;

	for (int i = 2; i <= 26; ++i)
		for (int j = 1; j < i; ++j)
			C[i][j] = static_cast<uint64>(C[i - 1][j - 1] + C[i - 1][j]);

	while (~scanf("%[^\n]s", s) && getchar())
	{
		if (s[0] == '0') break;

		len = strlen(s);
		ans = 0;
		for (int i = 0; i < len; ++i)
			ans += C[26][i];
		
		for (int i = 0; i < len; ++i)
		{
			if (i + 1 < len && s[i] > s[i + 1])
			{
				ans = 0;
				break;
			}

			int tmp = s[i] - ('a' + i);
			for (int j = 1; j <= tmp; ++j)
			{
				ans += C['z' - ('a' + i) - j][len - i - 1];
			}
		}

		printf("%llu\n", ans);
	}

	return 0;
}
