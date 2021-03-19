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
#include <vector>
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
vector<int> vec;
int N, M, x, now = 1, dis;

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &x);
		while (now <= x) vec.emplace_back(now++);

		auto it = find(vec.begin(), vec.end(), x);
		dis = vec.end() - it;

		if (dis > M + 1)
		{
			puts("no");
			return 0;
		}
		else
			vec.erase(it);
	}

	puts("yes");

	return 0;
}
