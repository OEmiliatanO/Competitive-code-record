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
#include <climits>
#include <cmath>
#include <algorithm>
#include <tuple>
#define ios_jazz ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define FOR(i, l, r) for (int i = (l); i < (r); ++i)
#define FORR(i, r, l) for (int i =(r); i >= (l); --i)
#define P(STR) puts(#STR)

using namespace std;

constexpr int Dir4[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
constexpr int Dir8[8][2] = { {-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 1} };
constexpr double EPS = 1e-8;
const double PI = acos(-1);

using int16 = short;
using uint16 = unsigned short;
using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using pii = pair<int, int>;

auto Equal = [](double a, double b) { return fabs(a - b) < EPS; };

/* mods */

/* main code */
#include <vector>

constexpr int MAXN = 1e5;
int n;
int64 a, b;
int64 arr[2][MAXN + 1]{};
int64 tmp[MAXN + 10];

enum { A, B };
int64 sort(int idx, int l = 0, int r = n)
{
	if (r == l)
	{
		if (idx == A && arr[idx][l] == INT64_MAX) return 0;
		else if (idx == B && arr[idx][l] == INT64_MIN) return 0;
		if (idx == A)
			return (arr[idx][l] >= 0);
		else
			return (arr[idx][r] <= 0);
	}

	int mid = (l + r) / 2;

	int64 Lval = sort(idx, l, mid);
	int64 Rval = sort(idx, mid + 1, r);
	int64 Nowval = 0;

	int64 lptr = l;
	int64 rptr = mid + 1LL;
	int64 N = 0;

	for (; lptr <= mid; ++lptr)
	{
		while (rptr <= r && arr[idx][lptr] >= arr[idx][rptr])
		{
			tmp[N++] = arr[idx][rptr++];
			Nowval += ((int64)mid - lptr + 1);
		}

		tmp[N++] = arr[idx][lptr];
	}

	while (lptr <= mid)
		tmp[N++] = arr[idx][lptr++];
	while (rptr <= r)
		tmp[N++] = arr[idx][rptr++];

	for (int i = 0; i < N; ++i)
		arr[idx][l + i] = tmp[i];

	return Nowval + Lval + Rval;
}

int main()
{
	scanf("%d %lld %lld", &n, &a, &b);

	FOR(i, 1, n + 1)
		scanf("%lld", &arr[0][i]);

	FOR(i, 1, n + 1)
	{
		arr[1][i] = arr[0][i] - b;
		arr[1][i] += arr[1][i - 1];
		arr[0][i] -= a;
		arr[0][i] += arr[0][i - 1];
	}

	arr[A][0] = INT64_MAX;
	arr[B][0] = INT64_MIN;

	reverse(arr[A], arr[A] + n + 1);

	printf("%lld\n", sort(A) + sort(B) - n * (n + 1LL) / 2);

	return 0;
}
