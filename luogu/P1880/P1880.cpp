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

constexpr int MAXN = 100;

int n;
int a[MAXN * 2 + 5];
int S[MAXN * 2 + 5]{};
int dpmax[MAXN * 2 + 5][MAXN * 2 + 5]{};
int dpmin[MAXN * 2 + 5][MAXN * 2 + 5];

int main()
{
	memset(dpmin, 0x7f, sizeof(int) * (MAXN * 2 + 5) * (MAXN * 2 + 5));

	scanf("%d", &n);
	
	FOR(i, 1, n + 1)
	{
		int x;
		scanf("%d", &x);

		a[i] = x;
		a[n + i] = x;
	}

	FOR(i, 1, 2 * n + 1)
		S[i] = S[i - 1] + a[i];

	FOR(i, 1, 2 * n + 1)
		dpmin[i][i] = 0;
	FOR(len, 2, n + 1)
	{
		FOR(i, 1, 2 * n)
		{
			int j = i + len - 1;
			int Sij = S[j] - S[i - 1];
			for (int k = i; k < j && k < 2 * n; ++k)
			{
				dpmax[i][j] = max(dpmax[i][j], dpmax[i][k] + dpmax[k + 1][j] + Sij);
				dpmin[i][j] = min(dpmin[i][j], dpmin[i][k] + dpmin[k + 1][j] + Sij);
			}
		}
	}

	FOR(i, 1, n + 1)
	{
		dpmax[1][n] = max(dpmax[1][n], dpmax[i][i + n - 1]);
		dpmin[1][n] = min(dpmin[1][n], dpmin[i][i + n - 1]);
	}

	printf("%d\n%d", dpmin[1][n], dpmax[1][n]);

	return 0;
}
