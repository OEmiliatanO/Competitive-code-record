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
#include <climits>

constexpr int MAXN = 1e6;

int n, m, op, i, j, k;
pii ans;

int arr[MAXN + 1];
int postree[(MAXN << 4) + 10]{}, Maxtree[(MAXN << 4) + 10]{}, Mintree[(MAXN << 4) + 10]{};

auto lson = [](int x) { return x << 1; };
auto rson = [](int x) { return x << 1 | 1; };

void maintain(int now)
{
	Maxtree[now] = max(Maxtree[lson(now)], Maxtree[rson(now)]);
	Mintree[now] = min(Mintree[lson(now)], Mintree[rson(now)]);
	postree[now] = postree[lson(now)] + postree[rson(now)];
}

void build(int l = 1, int r = n, int now = 1)
{
	if (l == r)
	{
		Mintree[now] = Maxtree[now] = arr[l];
		postree[now] = 1;
		return;
	}

	int mid = (l + r) >> 1;

	build(l, mid, lson(now));
	build(mid + 1, r, rson(now));

	maintain(now);
}

int findnth(int nth, int now = 1, int l = 1, int r = n)
{
	int mid = (l + r) >> 1;

	if (!postree[lson(now)] && !postree[rson(now)])
	{
		return r;
	}

	if (postree[lson(now)] < nth)
	{
		nth -= postree[lson(now)];
		return findnth(nth, rson(now), mid + 1, r);
	}
	else
	{
		return findnth(nth, lson(now), l, mid);
	}
}

void modify(int pos, int l = 1, int r = n, int now = 1)
{
	if (l == r)
	{
		Maxtree[now] = INT_MIN;
		Mintree[now] = INT_MAX;
		postree[now] = 0;

		return;
	}

	int mid = (l + r) >> 1;

	if (pos <= mid)
		modify(pos, l, mid, lson(now));
	else
		modify(pos, mid + 1, r, rson(now));

	maintain(now);
}

void earse(int pos)
{
	int realpos = findnth(pos);

	modify(realpos);
}

pii query(int ql, int qr, int now = 1, int l = 1, int r = n)
{
	if (ql <= l && r <= qr)
		return pii{ Mintree[now], Maxtree[now] };

	if (l > qr || ql > r)
		return pii{ INT_MAX, INT_MIN };

	int mid = (l + r) >> 1;

	pii Lf = query(ql, qr, lson(now), l, mid);
	pii Rf = query(ql, qr, rson(now), mid + 1, r);

	return pii{ min(Lf.first, Rf.first), max(Lf.second, Rf.second) };
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", arr + i);
	}

	build();

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

			ans = query(findnth(i), findnth(j));
			
			printf("%d %d\n", ans.first, ans.second);
		}
	}

	return 0;
}
