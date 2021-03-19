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
#include <vector>

using tiiii = tuple<int, int, int, int>;

constexpr int MAXN = 1e5, MAXK = 2e5;

/* BIT */
int BIT[MAXK + 1]{};
auto lowbit = [](int x) { return x & (-x); };
int ask(int pos)
{
	int res = 0;
	for (; pos; pos -= lowbit(pos))
		res += BIT[pos];
	return res;
}
void add(int pos, int value)
{
	for (; pos <= MAXK; pos += lowbit(pos))
		BIT[pos] += value;
}

int n, k;
int ans[MAXN + 1];
int cntdot[MAXN + 1];

enum { a, b, c, id };
tiiii ele[MAXN + 1], tmp[MAXN + 2];
int idx = 1;

void cdq(int l = 1, int r = n)
{
	if (l == r) return;

	int mid = (l + r) >> 1;
	cdq(l, mid); cdq(mid + 1, r);

	sort(ele + l, ele + mid + 1, [](const tiiii& lhs, const tiiii& rhs) { return (get<b>(lhs) < get<b>(rhs)) || (get<b>(lhs) == get<b>(rhs) && get<c>(lhs) < get<c>(rhs)); });
	sort(ele + mid + 1, ele + r + 1, [](const tiiii& lhs, const tiiii& rhs) { return (get<b>(lhs) < get<b>(rhs)) || (get<b>(lhs) == get<b>(rhs) && get<c>(lhs) < get<c>(rhs)); });
	
	int idx1 = l, idx2 = mid + 1;
	for (; idx2 <= r; ++idx2)
	{
		while (idx1 <= mid && get<b>(ele[idx1]) <= get<b>(ele[idx2]))
		{
			add(get<c>(ele[idx1]), cntdot[get<id>(ele[idx1])]);
			++idx1;
		}
		ans[get<id>(ele[idx2])] += ask(get<c>(ele[idx2]));
	}
	for (int i = l; i < idx1; ++i)
		add(get<c>(ele[i]), -cntdot[get<id>(ele[i])]);
}

int f[MAXN];
int main()
{
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; ++i)
	{
		scanf("%d %d %d", &get<a>(tmp[i]), &get<b>(tmp[i]), &get<c>(tmp[i]));
	}

	sort(tmp + 1, tmp + n + 1);
	for (int i = 1, cnt = 0; i <= n; ++i)
	{
		++cnt;
		if (get<a>(tmp[i]) != get<a>(tmp[i + 1]) || get<b>(tmp[i]) != get<b>(tmp[i + 1]) || get<c>(tmp[i]) != get<c>(tmp[i + 1]))
		{
			cntdot[idx] = cnt;
			ele[idx] = move(tmp[i]);
			get<id>(ele[idx]) = idx;
			++idx;
			cnt = 0;
		}
	}
	
	int copyn = n;

	n = idx - 1;
	cdq();

	for (int i = 1; i <= n; ++i)
		f[ans[i] + cntdot[i] - 1] += cntdot[i];

	for (int i = 0; i < copyn; ++i)
		printf("%d\n", f[i]);

	return 0;
}