#pragma warning( disable : 4996 )
/*
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
*/
#pragma GCC optimize("O3")
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
#include <climits>

constexpr int MAXN = 1e6;

int n, m, op, i, j, k;

int M;
int postree[(MAXN << 2) + 10]{}, Maxtree[(MAXN << 2) + 10]{}, Mintree[(MAXN << 2) + 10]{};

auto lson = [](int x) { return x << 1; };
auto rson = [](int x) { return x << 1 | 1; };

void maintain(int now)
{
	Mintree[now] = min(Mintree[lson(now)], Mintree[rson(now)]);
	Maxtree[now] = max(Maxtree[lson(now)], Maxtree[rson(now)]);
	postree[now] = postree[lson(now)] + postree[rson(now)];
}

void init()
{
	M = 1;
	while (M < n) M <<= 1;

	for (int i = M; i < n + M; ++i)
	{
		scanf("%d", Maxtree + i);
		Mintree[i] = Maxtree[i];
		postree[i] = 1;
	}
	for (int i = n + M; i <= rson(M - 1); ++i)
		Mintree[i] = INT_MAX, Maxtree[i] = INT_MIN;

	for (int i = M - 1; i; --i)
		maintain(i);

	return;
}

int findnth(int nth, int now = 1)
{
	for (; now < M;)
		if (postree[lson(now)] < nth)
			nth -= postree[lson(now)], now = rson(now);
		else
			now = lson(now);

	return now - M + 1;
}

void earse(int pos)
{
	int realpos = findnth(pos) + M - 1;

	Mintree[realpos] = INT_MAX;
	Maxtree[realpos] = INT_MIN;
	postree[realpos] = 0;

	while (realpos > 1)
	{
		maintain(realpos >> 1);
		realpos >>= 1;
	}
}

pii ans;
void query(int ql, int qr)
{
	ans = {INT_MAX, INT_MIN};

	ql = ql + M - 1, qr = qr + M - 1;

	ans.first = min(Mintree[ql], Mintree[qr]);
	ans.second = max(Maxtree[ql], Maxtree[qr]);

	while((ql ^ qr) != 1 && ql != qr)
	{
		if (!(ql & 1))
		{
			ans.first = min(ans.first, Mintree[ql ^ 1]);
			ans.second = max(ans.second, Maxtree[ql ^ 1]);
		}
		if ((qr & 1))
		{
			ans.first = min(ans.first, Mintree[qr ^ 1]);
			ans.second = max(ans.second, Maxtree[qr ^ 1]);
		}
		
		ql >>= 1, qr >>= 1;
	}
}

int main()
{
	scanf("%d %d", &n, &m);

	init();

	while (m--)
	{
		scanf("%d", &op);
		if (op == 1)
		{
			scanf("%d", &k);

			earse(k);
		}
		else if (op == 2)
		{
			scanf("%d %d", &i, &j);

			query(findnth(i), findnth(j));

			printf("%d %d\n", ans.first, ans.second);
		}
	}

	return 0;
}

