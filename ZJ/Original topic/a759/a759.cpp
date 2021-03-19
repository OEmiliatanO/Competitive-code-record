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

/* main code */

int A, B, C, N;
char s[1000000];
int popcnt[33];
auto convert = [](char ch) -> int {return (ch >= '0' && ch <= '9' ? ch - '0' : ch - 'A' + 10); };

int main()
{
	while (~scanf("%d", &B))
	{
		memset(popcnt, 0, sizeof(int) * 33);

		scanf("%d", &N);
		for (int i = 0, x, cnt; i < N; ++i)
		{
			cnt = A = 0;
			
			scanf("%d", &x);
			scanf("%s", s);

			for (int i = 0; s[i]; ++i)
				A = convert(s[i]) + A * x;

			if (A < B)
			{
				C = A + B;

				while (C)
				{
					++cnt;
					C -= (C & -C);
				}
				++popcnt[cnt];
			}
		}

		for (int i = 32; i >= 0; --i)
			if (popcnt[i])
			{
				printf("%d %d\n", i, popcnt[i]);
				break;
			}

	}

	return 0;
}
