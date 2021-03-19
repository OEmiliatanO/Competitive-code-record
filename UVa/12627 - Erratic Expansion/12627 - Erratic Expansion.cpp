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

int T;
int K, A, B;
int64 threePOW[31] = {1};

int64 f(int k, int i)
{
	if (i > (1 << k)) return 0;
	if (k == 0 || i == 1) return threePOW[k];

	if (i <= (1 << (k - 1))) return 2 * f(k - 1, i) + threePOW[k - 1];
	else return f(k - 1, i - (1 << (k - 1)));
}

int main()
{
	FOR(i, 1, 31) threePOW[i] = threePOW[i - 1] * 3;

	scanf("%d", &T);

	FOR(kase, 1, T + 1)
	{
		scanf("%d %d %d", &K, &A, &B);

		printf("Case %d: %lld\n", kase, f(K, A) - f(K, B + 1));
	}

	return 0;
}
