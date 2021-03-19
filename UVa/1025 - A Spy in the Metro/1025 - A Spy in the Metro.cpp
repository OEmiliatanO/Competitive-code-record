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

constexpr int MAXN = 50;
constexpr int MAXT = 200;

int N, T, M;
int t[MAXN + 1]{};

enum {fromL, fromR};
bool hasTrain[MAXN + 1][MAXT + 1][2];

int dp[MAXT + 1][MAXN + 1];

int kase = 1;

int main()
{
	while (~scanf("%d", &N), N)
	{
		memset(hasTrain, false, sizeof(bool) * (MAXN + 1) * (MAXT + 1) * 2);

		scanf("%d", &T);
		
		FOR(i, 1, N) scanf("%d", &t[i]);

		FOR(from, 0, 2)
		{
			scanf("%d", &M);
			FOR(i, 1, M + 1)
			{
				int d;
				scanf("%d", &d);

				for (int station = (from ? N : 1); station != (from ? 1 : N); station += (from ? -1 : 1))
				{
					hasTrain[station][d][from] = true;
					d += t[station - from];
				}
			}
		}

		memset(dp, 0x5f, sizeof(int) * (MAXT + 1) * (MAXN + 1));

		dp[T][N] = 0;

		for (int nowt = T - 1; nowt >= 0; --nowt)
		{
			for (int station = 1; station <= N; ++station)
			{
				int& ans = dp[nowt][station];
				
				ans = min(ans, dp[nowt + 1][station] + 1);

				if (nowt + t[station] <= T && station != N && hasTrain[station][nowt][fromL])
					ans = min(ans, dp[nowt + t[station]][station + 1]);

				if (nowt + t[station - 1] <= T && station != 1 && hasTrain[station][nowt][fromR])
					ans = min(ans, dp[nowt + t[station - 1]][station - 1]);
			}
		}

		printf("Case Number %d: ", kase++);

		if (dp[0][1] == 0x5f5f5f5f) puts("impossible");
		else printf("%d\n", dp[0][1]);
	}

	return 0;
}