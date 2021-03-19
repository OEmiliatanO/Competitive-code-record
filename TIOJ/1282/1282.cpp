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
constexpr int MAXN = 1e5;

int64 gcd(int64 x, int64 y)
{
	return y ? gcd(y, x % y) : x;
}

int N, Q, l, r;
int64 nativeArr[MAXN + 1], k;
int op;

/* segment tree */
auto lson = [](int x) { return x << 1; };
auto rson = [](int x) { return x << 1 | 1; };
int64 tree[(MAXN + 1) * 4];
void maintain(int);
void sg_build(int = 1, int = 1, int = N);
int64 sg_ask(int, int, int = 1, int = 1, int = N);
void sg_add(int, int64, int = 1, int = 1, int = N);

/* BIT */
int64 BIT[MAXN + 1];
auto lowbit = [](int x) { return x & (-x); };
void bit_add(int, int64);
int64 bit_ask(int);

int main()
{
	scanf("%d %d", &N, &Q);

	for (int i = 1; i <= N; ++i)
		scanf("%lld", nativeArr + i);

	sg_build();

	while (Q--)
	{
		scanf("%d", &op);

		if (op == 1)
		{
			scanf("%d %d %lld", &l, &r, &k);
			sg_add(l, k);
			bit_add(l, k);
			if (r + 1 <= N)
			{
				sg_add(r + 1, -k);
				bit_add(r + 1, -k);
			}
		}
		else if (op == 2)
		{
			scanf("%d %d", &l, &r);
			if (l == r)
				printf("%lld\n", nativeArr[l] + bit_ask(l));
			else
				printf("%lld\n", abs(gcd(nativeArr[l] + bit_ask(l), sg_ask(l + 1, r))));
		}
	}

	return 0;
}

/* BIT */
void bit_add(int pos, int64 x)
{
	while (pos <= MAXN)
	{
		BIT[pos] += x;
		pos += lowbit(pos);
	}
}
int64 bit_ask(int pos)
{
	int64 res = 0;
	while (pos)
	{
		res += BIT[pos];
		pos -= lowbit(pos);
	}
	return res;
}

/* segment tree */
void maintain(int now)
{
	tree[now] = gcd(tree[lson(now)], tree[rson(now)]);
}
void sg_build(int now, int l, int r)
{
	if (l == r)
	{
		tree[now] = nativeArr[l] - nativeArr[l - 1];
		return;
	}
	int mid = (l + r) >> 1;
	sg_build(lson(now), l, mid);
	sg_build(rson(now), mid + 1, r);

	maintain(now);
}
int64 sg_ask(int ql, int qr, int now, int nowl, int nowr)
{
	if (ql <= nowl && nowr <= qr)
		return tree[now];
	if (nowr < ql || nowl > qr)
		return 0;

	int mid = (nowl + nowr) >> 1;
	int64 ans = 0;

	ans = gcd(ans, sg_ask(ql, qr, lson(now), nowl, mid));
	ans = gcd(ans, sg_ask(ql, qr, rson(now), mid + 1, nowr));

	return ans;
}
void sg_add(int pos, int64 val, int now, int nowl, int nowr)
{
	if (nowl == nowr)
	{
		tree[now] += val;
		return;
	}

	int mid = (nowl + nowr) >> 1;

	if (pos <= mid) sg_add(pos, val, lson(now), nowl, mid);
	else sg_add(pos, val, rson(now), mid + 1, nowr);

	maintain(now);
}