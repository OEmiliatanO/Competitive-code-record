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

using int16 = short;
using uint16 = unsigned short;
using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using pii = pair<int, int>;


/* main code */
using tiii = tuple<int, int, int>;

/* BIT */
constexpr int MAXE = 32767;
auto lowbit = [](int x) { return x & -x; };
int BIT[MAXE + 1];
void updata(int, int);
int query(int);

constexpr int MAXN = 1e4;

int T, N, ans;

tiii work[MAXN + 1];

int main()
{
	scanf("%d", &T);

	while (T-- && scanf("%d", &N))
	{
		ans = 0;

		for (int i = 0, S, E, C; i < N; ++i)
		{
			scanf("%d %d %d", &S, &E, &C);
			work[i] = { S, E, C };
		}
		
		sort(work, work + N);
		memset(BIT, 0, sizeof(int) * (MAXE + 1));

		for (int i = 0; i < N; ++i)
		{
			get<2>(work[i]) += query(get<0>(work[i]));
			updata(get<1>(work[i]), get<2>(work[i]));
			ans = max(get<2>(work[i]), ans);
		}

		printf("%d\n", ans);
	}

	return 0;
}

void updata(int pos, int x)
{
	for (; pos <= MAXE; pos += lowbit(pos))
		BIT[pos] = max(BIT[pos], x);
}

int query(int pos)
{
	int res = 0;

	for (; pos; pos -= lowbit(pos))
		res = max(BIT[pos], res);

	return res;
}
