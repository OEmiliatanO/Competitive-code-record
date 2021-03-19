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

int arr[3][3000];
int A[3000][3000];
int n;


int main()
{
	scanf("%d", &n);
	
	for (int i = 0; i < n * n; ++i)
		scanf("%d", &A[i / n][i % n]);

	for (int t = 0; t < 2; ++t)
		for (int i = 0, x, sum = 0; i < n * n; ++i)
		{
			scanf("%d", &x);
			sum ^= x;
			if (i % n == n - 1) arr[t][i / n] = sum, sum = 0;
		}

	for (int i = 0, sum = 0; i < n * n; ++i)
	{
		sum ^= A[i / n][i % n] & arr[0][i % n];
		if (i % n == n - 1) arr[2][i / n] = sum, sum = 0;
	}

	for(int i = 0; i < n; ++i)
		if (arr[1][i] != arr[2][i])
		{
			puts("NO");
			return 0;
		}

	puts("YES");

	return 0;
}
