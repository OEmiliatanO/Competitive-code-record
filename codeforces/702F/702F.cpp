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

constexpr int MAXN = 2e5;

enum { Money, BuyAmount };
struct node
{
	int sz, val[2], lztag[2];
	int id;
	int pri;

	node* l, * r;

	node() = default;
	node(int money, int buyamount, int ID)
	{
		id = ID;
		pri = rand();
		val[Money] = money;
		val[BuyAmount] = buyamount;
		lztag[0] = lztag[1] = 0;
		sz = 1;
		l = r = nullptr;
	}

	static node mempool[MAXN + 10], * ptr;
}*root, node::mempool[MAXN + 10], *node::ptr = node::mempool;

void pull(node *t)
{
	if (!t) return;
	t->sz = 1;
	if (t->l) t->sz += t->l->sz;
	if (t->r) t->sz += t->r->sz;

	return;
}

void push(node *t)
{
	if (!t) return;

	FOR(i, 0, 2)
	{
		t->val[i] += t->lztag[i];

		if (t->l) t->l->lztag[i] += t->lztag[i];
		if (t->r) t->r->lztag[i] += t->lztag[i];

		t->lztag[i] = 0;
	}
}

void split(node *t, int x, node *&a, node *&b)
{
	if (!t)
	{
		a = b = nullptr;
		return;
	}

	push(t);
	if (t->val[Money] <= x)
	{
		a = t;
		push(a);
		split(t->r, x, a->r, b);
		pull(a);
	}
	else
	{
		b = t;
		push(b);
		split(t->l, x, a, b->l);
		pull(b);
	}
}

node* merge(node* a, node* b)
{
	if (!a || !b)
		return a ? a : b;

	if (a->pri > b->pri)
	{
		push(a);
		a->r = merge(a->r, b);
		pull(a);
		return a;
	}
	else
	{
		push(b);
		b->l = merge(a, b->l);
		pull(b);
		return b;
	}
}

void insert(int id, int money, int buyamount = 0)
{
	node* l, * r, * now;

	split(root, money, l, r);
	now = new(node::ptr++) node(money, buyamount, id);
	root = merge(merge(l, now), r);
}

int n;
pii clothes[MAXN + 1];
int k;
int b[MAXN + 1];

void magic_merge(node *&target, node *from)
{
	if (!from) return;

	push(from);

	node* nexl, * nexr;
	nexl = from->l, nexr = from->r;
	from->l = from->r = nullptr;

	magic_merge(target, nexl);

	node* l, * r;
	split(target, from->val[Money], l, r);
	target = merge(merge(l, from), r);

	magic_merge(target, nexr);
}

int ans[MAXN];

void travel(node *now)
{
	if (!now) return;

	push(now);

	travel(now->l);
	ans[now->id] = now->val[BuyAmount];
	travel(now->r);
}

int main()
{
	scanf("%d", &n);
	FOR(i, 0, n)
		scanf("%d %d", &clothes[i + 1].second, &clothes[i + 1].first);

	sort(clothes + 1, clothes + 1 + n, [](const pii& lhs, const pii& rhs) {
		return (lhs.first > rhs.first) || (lhs.first == rhs.first && lhs.second < rhs.second);
		});

	scanf("%d", &k);
	FOR(i, 0, k)
	{
		scanf("%d", &b[i + 1]);
		insert(i, b[i + 1]);
	}

	node* l, * r, * tmp;
	FOR(i, 1, n + 1)
	{
		split(root, clothes[i].second - 1, l, r);

		if (r != nullptr)
		{
			r->lztag[Money] -= clothes[i].second;
			++r->lztag[BuyAmount];
		}

		split(r, clothes[i].second - 1, tmp, r);

		magic_merge(l, tmp);

		root = merge(l, r);
		
	}

	travel(root);

	FOR(i, 0, k)
	{
		printf("%d ", ans[i]);
	}

	return 0;
}
