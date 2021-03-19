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
#include <vector>
#include <map>
#include <stack>
#include <iterator>

int T, N;
char s[10];

map<set<int>, int> hasher;
vector<set<int>> contain;
int ID(set<int> S)
{
	if (hasher.find(S) == hasher.end())
	{
		contain.emplace_back(S);
		return hasher[S] = contain.size() - 1;
	}
	return hasher[S];
}

stack<int> st;

int main()
{
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &N);
		while (N--)
		{
			scanf("%s", s);
			if (s[0] == 'P')
			{
				st.emplace(ID(set<int>()));
			}
			else if (s[0] == 'D')
			{
				st.emplace(st.top());
			}
			else
			{
				set<int> S1, S2, res;
				S1 = contain[st.top()]; st.pop();
				S2 = contain[st.top()]; st.pop();
				if (s[0] == 'U')
				{
					set_union(S1.begin(), S1.end(), S2.begin(), S2.end(), inserter(res, res.end()));
					st.emplace(ID(res));
				}
				else if (s[0] == 'I')
				{
					set_intersection(S1.begin(), S1.end(), S2.begin(), S2.end(), inserter(res, res.end()));
					st.emplace(ID(res));
				}
				else if (s[0] == 'A')
				{
					S2.emplace(ID(S1));
					st.emplace(ID(S2));
				}
			}
			printf("%d\n", contain[st.top()].size());
		}
		puts("***");
	}

	return 0;
}
