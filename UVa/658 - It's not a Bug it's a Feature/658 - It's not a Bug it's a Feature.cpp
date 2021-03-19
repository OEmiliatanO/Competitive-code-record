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
#include <queue>
#include <unordered_map>

constexpr int MAXM = 100;
constexpr int MAXST = 1 << 20;

struct Com
{
	int time, cond_none, cond_exit, fix_remove, fix_add;
};

int n, m;
Com patches[MAXM + 1];
int ST[MAXST];

void bfs(int inital = (1 << n) - 1, int tottime = 0)
{
	memset(ST, 0x7f, sizeof(int) * MAXST);
	priority_queue<pii, vector<pii>, greater<pii>> qu;

	qu.emplace(tottime, inital);
	ST[inital] = tottime;

	while (qu.size())
	{
		pii now = qu.top(); qu.pop();

		if (!now.second) break;
		if ((ST[now.second] < now.first)) continue;

		for (int i = 1, state, ttime; i <= m; ++i)
		{
			state = now.second;
			if ((state & patches[i].cond_none) || (state & patches[i].cond_exit) != patches[i].cond_exit)
				continue;

			state = state & (~patches[i].fix_remove);
			state = state | (patches[i].fix_add);
			ttime = now.first + patches[i].time;

			if (ST[state] > ttime)
			{
				qu.emplace(ttime, state);
				ST[state] = ttime;
			}
		}
	}
}

int main()
{
	int kase = 1;
	while (~scanf("%d %d", &n, &m), n | m)
	{
		for (int i = 1, t; i <= m; ++i)
		{
			scanf("%d", &patches[i].time); getchar();
			patches[i].cond_exit = patches[i].cond_none = patches[i].fix_add = patches[i].fix_remove = 0;

			for (int j = 0, ch; j < n; ++j)
			{
				ch = getchar();
				patches[i].cond_none = (patches[i].cond_none << 1) | (ch == '-');
				patches[i].cond_exit = (patches[i].cond_exit << 1) | (ch == '+');
			}
			getchar();
			for (int j = 0, ch; j < n; ++j)
			{
				ch = getchar();
				patches[i].fix_remove = (patches[i].fix_remove << 1) | (ch == '-');
				patches[i].fix_add = (patches[i].fix_add << 1) | (ch == '+');
			}
		}

		bfs();

		printf("Product %d\n", kase++);
		if (ST[0] != 0x7f7f7f7f)
			printf("Fastest sequence takes %d seconds.\n", ST[0]);
		else
			puts("Bugs cannot be fixed.");
		puts("");
	}

	return 0;
}
