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
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>

constexpr int MAXN = 200;

using umap = unordered_map<string, int>;

int n;

umap hasher;
string s, k;
int idx;
int Hash(string x)
{
	if (hasher.find(x) == hasher.end())
		return (hasher[x] = idx++);
	return hasher[x];
}

vector<int> G[MAXN + 1];
int root;

int DP[MAXN + 1][2];
bool theChosenOne[MAXN + 1][2];

void dfs(int now)
{
	int sum = 0;

	DP[now][0] = 0, DP[now][1] = 1;

	for (auto nex : G[now])
	{
		dfs(nex);

		if (DP[nex][0] > DP[nex][1])
		{
			theChosenOne[now][0] &= theChosenOne[nex][0];
			sum += DP[nex][0];
		}
		else
		{
			theChosenOne[now][0] &= theChosenOne[nex][1];
			sum += DP[nex][1];
		}

		DP[now][1] += DP[nex][0];

		theChosenOne[now][0] &= (DP[nex][0] != DP[nex][1]);
		theChosenOne[now][1] &= theChosenOne[nex][0];
	}

	DP[now][0] = sum;
	DP[now][1] = (G[now].size() == 0 ? 1 : DP[now][1]);
}

int main()
{
	while (cin >> n, n)
	{
		memset(theChosenOne, true, sizeof(theChosenOne));
		hasher.clear();

		idx = 0;
		for (int i = 0; i <= n; ++i)
			G[i].clear();

		cin >> s;
		root = Hash(s);

		for (int i = 0, fa, son; i < n - 1; ++i)
		{
			cin >> s >> k;
			fa = Hash(k);
			son = Hash(s);
			G[fa].emplace_back(son);
		}

		dfs(0);

		if (DP[0][0] < DP[0][1])
			swap(DP[0][0], DP[0][1]), swap(theChosenOne[0][0], theChosenOne[0][1]);

		if (DP[0][0] == DP[0][1])
			theChosenOne[0][0] = false;
		
		printf("%d ", DP[0][0]);
		puts((theChosenOne[0][0] ? "Yes" : "No"));
	}

	return 0;
}

