#pragma warning( disable : 4996 )
/*
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
*/
#pragma GCC optimize("O3")
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <tuple>
#define ios_jazz ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

using int16 = short;
using uint16 = unsigned short;
using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using pii = pair<int, int>;

/* main code */
using tiiii = tuple<int, int, int, int>;

enum {Num, L, R, K};

const int MAXN = 1e5;
const int MAXM = 5e5;

tiiii query[MAXM];
int n, m, queryCnt = 0;

struct obj
{
	int64 value;
	int pos;
	obj() = default;
	obj(int v, int p) : value(v), pos(p) {};
	bool operator< (obj B) const
	{
		return value < B.value;
	}
}tH[MAXN + 1];

int64 ans[MAXM], S[MAXN + 1]{};

/* BIT */
auto lowbit = [](const int &x) noexcept { return x & -x; };
int BIT[MAXN + 1];
int ask(int) noexcept;
void add1(int) noexcept;
/* BIT */

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &tH[i].value);
		S[i] = S[i - 1] + tH[i].value;
		tH[i].pos = i;
	}

	for (int i = 0, op, l, r; i < m; ++i)
	{
		scanf("%d", &op);
		if (op == 1)
		{
			scanf("%d", &l);
			*S = (*S + l) % MAXN;
		}
		else
		{
			scanf("%d %d", &l, &r);
			get<Num>(query[queryCnt]) = queryCnt;
			get<L>(query[queryCnt]) = l;
			get<R>(query[queryCnt]) = r;
			get<K>(query[queryCnt]) = MAXN - *S;
			++queryCnt;
		}
	}
	*S = 0;

	sort(tH + 1, tH + 1 + n);
	sort(query, query + queryCnt, [](const tiiii& lhs, const tiiii& rhs) {
		return get<K>(lhs) < get<K>(rhs);
		});

	for (int i = 0, x = 1; i < queryCnt; ++i)
	{
		int p = upper_bound(tH + 1, tH + 1 + n, obj{ get<K>(query[i]), 1 }) - tH;

		int qr = get<R>(query[i]), ql = get<L>(query[i]), k = MAXN - get<K>(query[i]);

		while (x < p)
			add1(tH[x++].pos);

		ans[get<Num>(query[i])] = (S[qr] - S[ql - 1] + k * (int64)(qr - ql + 1)) - MAXN * (int64)(qr - ql + 1 - (ask(qr) - ask(ql - 1)));
	}

	for (int i = 0; i < queryCnt; ++i)
		printf("%lld\n", ans[i]);

	return 0;
}

int ask(int pos) noexcept
{
	int res = 0;

	for (; pos; pos -= lowbit(pos))
		res += BIT[pos];

	return res;
}

void add1(int pos) noexcept
{
	for (; pos <= MAXN; pos += lowbit(pos))
		++BIT[pos];
}
