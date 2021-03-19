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

using int16 = short;
using uint16 = unsigned short;
using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using pii = pair<int, int>;

/* main code */
int M, arr[20], all = 0;

int main()
{
	scanf("%d", &M);
	for (int i = 0; i < M && scanf("%d", &arr[i]); all += arr[i], ++i);

	for (int i = 1, P, Q; i < 1 << M; ++i)
	{
		P = 0;
		for (int j = 0; 1 << j < i; ++j)
		{
			if (i & (1 << j))
				P += arr[j];
		}
		Q = all - P;
		Q = (Q == 10007 ? 10007 : Q % 10007);
		P = (P == 10007 ? 10007 : P % 10007);
		if (Q == P)
		{
			puts("YES");
			return 0;
		}
	}

	puts("NO");

	return 0;
}
