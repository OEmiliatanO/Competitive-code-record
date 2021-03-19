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
#include <stack>

int N, H, ans = 0;
stack<pii> st;

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &H);
		
		int tmp = i;
		while (st.size() && H < st.top().first)
		{
			tmp = st.top().second;
			ans = max(ans, (i - tmp) * st.top().first);
			st.pop();
		}
		st.emplace(pii{ H, tmp });
	}

	while (st.size())
	{
		ans = max(ans, (N + 1 - st.top().second) * st.top().first);
		st.pop();
	}

	printf("%d", ans);
	return 0;
}
