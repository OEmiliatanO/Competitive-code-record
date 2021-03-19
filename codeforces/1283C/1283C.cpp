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

constexpr int MAXN = 2e5;

int n;
int arr[MAXN + 1];
bool gave[MAXN + 1]{}, got[MAXN + 1]{};
vector<int> a, b;

int main()
{
	scanf("%d", &n);

	FOR(i, 1, n + 1)
	{
		scanf("%d", &arr[i]);
		got[arr[i]] = true;
		gave[i] = (arr[i] != 0);
	}

	FOR(i, 1, n + 1)
	{
		if (!gave[i]) a.emplace_back(i);
		if (!got[i]) b.emplace_back(i);
	}

	FOR(i, 0, a.size())
	{
		if (a[i] == b[i])
			swap(b[i], b[(i + 1) % b.size()]);
	}

	FOR(i, 0, a.size())
	{
		arr[a[i]] = b[i];
	}

	FOR(i, 1, n + 1)
		printf("%d ", arr[i]);

	return 0;
}
