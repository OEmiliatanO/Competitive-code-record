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
#include <stack>
#include <vector>

constexpr int MAXN = 1e3;

int n;
int dfs_tavl[MAXN + 1], pos[MAXN + 1];

vector<int> G[MAXN + 1];
stack<int> st;

int main()
{
	while (~scanf("%d", &n))
	{
		for (int i = 0; i <= n; ++i)
			G[i].clear();

		st = stack<int>();

		for (int i = 0, x; i < n; ++i)
		{
			scanf("%d", &x);
			pos[x] = i;
		}

		for (int j = 0; j < n; ++j)
			scanf("%d", dfs_tavl + j);

		int root = dfs_tavl[0];

		st.emplace(root);
		for (int i = 1, node; i < n; ++i)
		{
			while (true)
			{
				node = st.top();
				if (node == root || pos[node] + 1 < pos[dfs_tavl[i]])
				{
					G[node].emplace_back(dfs_tavl[i]);
					st.emplace(dfs_tavl[i]);
					break;
				}
				else
					st.pop();
			}
		}

		for (int i = 1; i <= n; ++i)
		{
			printf("%d:", i);
			for (auto nex : G[i])
				printf(" %d", nex);
			puts("");
		}
	}

	return 0;
}
