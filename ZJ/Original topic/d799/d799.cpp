#pragma warning( disable : 4996 )
/*
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
*/
#include <cstdio>

using namespace std;

using int16 = short;
using uint16 = unsigned short;
using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;

/* main code */
constexpr int MAXN = 500000;

auto lson = [](int x) { return x << 1; };
auto rson = [](int x) { return x << 1 | 1; };
int N, Q;
int M;
int64 tree[MAXN * 4 + 10], tag[MAXN * 4 + 10];

void maintain(int x)
{
	tree[x] = tree[lson(x)] + tree[rson(x)];
}
void build()
{
	for (M = 1; M < N; M <<= 1);
	for (int i = M + 1; i < N + M + 1; ++i) scanf("%lld", &tree[i]);
	for (int i = M - 1; i; --i)
		maintain(i);
}
void update_node(int index, int value)
{
	tree[index += M] += value;
	for (index >>= 1; index; index >>= 1)
		maintain(index);
}
void update(int l, int r, int value)
{
	int64 ln = 0, rn = 0, nn = 1;
	for (l = l + M - 1, r = r + M + 1; l ^ r ^ 1; l >>= 1, r >>= 1, nn <<= 1)
	{
		tree[l] += value * ln;
		tree[r] += value * rn;
		if (~l & 1)
		{
			tag[l ^ 1] += value;
			tree[l ^ 1] += value * nn;
			ln += nn;
		}
		if (r & 1)
		{
			tag[r ^ 1] += value;
			tree[r ^ 1] += value * nn;
			rn += nn;
		}
	}
	for (; l; l >>= 1, r >>= 1)
	{
		tree[l] += value * ln;
		tree[r] += value * rn;
	}
}

int64 query(int l, int r)
{
	int64 ln = 0, rn = 0, nn = 1;
	int64 ans = 0;
	for (l = l + M - 1, r = r + M + 1; l ^ r ^ 1; l >>= 1, r >>= 1, nn <<= 1)
	{
		if (tag[l]) ans += tag[l] * ln;
		if (tag[r]) ans += tag[r] * rn;

		if (~l & 1)
		{
			ans += tree[l ^ 1];
			ln += nn;
		}
		if (r & 1)
		{
			ans += tree[r ^ 1];
			rn += nn;
		}
	}
	for (; l; l >>= 1, r >>= 1)
	{
		ans += tag[l] * ln;
		ans += tag[r] * rn;
	}
	return ans;
}

int main()
{
	scanf("%d", &N);
	build();
	scanf("%d", &Q);
	for (int i = 0, op, x, y, k; i < Q; ++i)
	{
		scanf("%d", &op);
		if (op == 1)
		{
			scanf("%d %d %d", &x, &y, &k);
			update(x, y, k);
		}
		else if(op == 2)
		{
			scanf("%d %d", &x, &y);
			printf("%lld\n", query(x, y));
		}
		else
		{
			scanf("%d %d", &x, &k);
			update_node(x, k);
		}
	}

	return 0;
}
