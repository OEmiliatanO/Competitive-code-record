﻿#pragma warning( disable : 4996 )
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
#include <unordered_map>

int q, n, pow2[31];
int64 s;

unordered_map<int64, int> converter;

int main()
{
	for (int i = 0; i <= 29; ++i)
		converter[(int64)1 << i] = i;

	scanf("%d", &q);
	while (q--)
	{
		memset(pow2, 0, sizeof(int) * 31);

		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%lld", &s);
			++pow2[converter[s]];
		}

		for (int i = 0; i < 13; ++i)
			if (pow2[i] >= 2)
				pow2[i + 1] += pow2[i] / 2;

		if (pow2[11] != 0)
			puts("yes");
		else
			puts("no");
	}


	return 0;
}
