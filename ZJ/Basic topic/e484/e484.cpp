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

constexpr int MAXN = 1e4;

bool isprime[MAXN + 1]{};
int n;

int main()
{
	memset(isprime, true, MAXN);

	isprime[0] = isprime[1] = false;
	for (int i = 2, t; i * i <= MAXN; ++i)
	{
		if (isprime[i])
		{
			t = 2;
			while (i * t <= MAXN)
				isprime[i * t++] = false;
		}
	}

	scanf("%d", &n);
	puts((isprime[n] ? "yes" : "no"));

	return 0;
}
