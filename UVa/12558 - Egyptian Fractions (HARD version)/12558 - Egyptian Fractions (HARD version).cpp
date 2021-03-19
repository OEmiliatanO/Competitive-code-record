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
constexpr int MAXN = 1e4;

int T;
int64 maxd;
int64 ans[MAXN], tmp[MAXN], a, b, k;
int64 Restrict[6];

int64 get_first(int64 a, int64 b)
{
	int64 res = 1;
	while (a * res < b) ++res;
	return res;
}
int64 gcd(int64 a, int64 b)
{
	return (b == 0 ? a : gcd(b, a % b));
}

bool isbetter()
{
	FORR(i, maxd, 0)
		if (ans[i] != tmp[i])
			return ans[i] == -1 || ans[i] > tmp[i];

	return false;
}

bool dfs(int d, int64 _c, int64 _a, int64 _b)
{
	if (d == maxd)
	{
		if (_b % _a) return false;

		FOR(i, 0, k)
			if (_b / _a == Restrict[i]) return false;
		
		tmp[d] = _b / _a;

		if (isbetter())
			memcpy(ans, tmp, sizeof(int64) * (d + 1));

		return true;
	}

	bool ok = false;
	for (int64 c = max(_c, get_first(_a, _b)); ; ++c)
	{
		if ((maxd - d + 1) * _b <= _a * c) break;
		
		bool restr = true;
		FOR(i, 0, k)
			if (c == Restrict[i])
			{
				restr = false;
				break;
			}
		if (!restr) continue;

		tmp[d] = c;

		int64 bb = _b * c;
		int64 aa = _a * c - _b;
		int64 GCD = gcd(aa, bb);

		if (dfs(d + 1, c + 1, aa / GCD, bb / GCD))
			ok = true;
	}

	return ok;
}

int main()
{
	int kase = 1;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%lld %lld %lld", &a, &b, &k);
		FOR(i, 0, k)
			scanf("%lld", &Restrict[i]);

		for (maxd = 1; ; ++maxd)
		{
			memset(ans, -1, sizeof(int64) * MAXN);
			if (dfs(0, get_first(a, b), a, b))
				break;
		}

		printf("Case %d: %lld/%lld=1/%lld", kase++, a, b, ans[0]);
		FOR(i, 1, maxd + 1)
			printf("+1/%lld", ans[i]);

		puts("");
	}

	return 0;
}
