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
#include <set>
constexpr int MAXN = 5e5;

/* BIT */
int64 BIT[MAXN + 1]{};
auto lowbit = [](int x) { return x & (-x); };
int64 ask(int pos)
{
	int64 res = 0;
	for (; pos; pos -= lowbit(pos))
		res += BIT[pos];

	return res;
}
void add(int pos, int val)
{
	for (; pos <= MAXN; pos += lowbit(pos))
		BIT[pos] += val;
}

set<int> Set;
int n, m, a, b;
int64 ans;
int A[MAXN + 1]{};

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) Set.emplace(i);

	while (m--)
	{
		scanf("%d %d", &a, &b);
		A[a] = b;
		Set.erase(b);
	}

	for (int i = 1; i <= n; ++i)
		if (!A[i])
		{
			A[i] = *Set.begin();
			Set.erase(Set.begin());
		}
	
	ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans += (int64)i - 1 - ask(A[i]);
		add(A[i], 1);
	}

	printf("%lld", ans);

	return 0;
}
