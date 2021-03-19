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

constexpr int MAXN = 1e5;

set<int> pos[27];
char s[MAXN + 2];
int q;

int main()
{
	scanf("%s", s + 1);

	for (int i = 1; s[i]; ++i)
		pos[s[i] - 'a'].emplace(i);

	scanf("%d", &q);

	for (int i = 0, op, x, y; i < q; ++i)
	{
		scanf("%d", &op);

		if (op == 1)
		{
			char ch;
			scanf("%d %c", &x, &ch);

			pos[s[x] - 'a'].erase(x);
			pos[ch - 'a'].emplace(x);
			s[x] = ch;
		}
		else
		{
			scanf("%d %d", &x, &y);
			int cnt = 0;
			for (int i = 0; i < 26; ++i)
			{
				auto it = pos[i].lower_bound(x);
				cnt += (it != pos[i].end() && *it <= y);
			}
			printf("%d\n", cnt);
		}
	}

	return 0;
}
