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
constexpr int MAXN = 1e5;
int arr[MAXN + 1]{}, pre[MAXN + 1]{}, a, b;

int main()
{
	for (int i = 1; i <= MAXN; ++i)
	{
		arr[i] = arr[i - 1] ^ i;
		pre[i] = pre[i - 1] ^ arr[i];
	}

	while (~scanf("%d %d", &a, &b))
	{
		if (a > b) swap(a, b);

		printf("%d\n", pre[b] ^ pre[a - 1]);
	}

	return 0;
}
