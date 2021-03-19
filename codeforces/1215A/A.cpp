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

int a1, a2, k1, k2, n;
int n1;

int main()
{
	scanf("%d %d %d %d %d", &a1, &a2, &k1, &k2, &n);

	n1 = n;

	if ((k1 - 1) * a1 + (k2 - 1) * a2 >= n)
	{
		printf("0 ");
	}
	else
	{
		n1 -= (k1 - 1) * a1 + (k2 - 1) * a2;
		printf("%d ", (n1 > a1 + a2 ? a1 + a2 : n1));
	}

	n1 = n;

	int cnt = 0;

	if (k1 > k2)
	{
		swap(k1, k2);
		swap(a1, a2);	
	}

	if (n1 / k1 > a1)
	{
		n1 = n1 - a1 * k1;
		cnt += a1;
		cnt += (n1 / k2);
	}
	else
	{
		cnt += n1 / k1;
	}

	printf("%d", cnt);

	return 0;
}
