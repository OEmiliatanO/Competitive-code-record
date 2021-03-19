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

#define FOR(i, l, r) for (int i = (l); i < (r); ++i)
#define FORR(i, r, l) for (int i = (r); i >= (l); --i)

char s[100];
vector<int> arr;

int main()
{
	while (~scanf("%[^\n]s", s) && getchar())
	{
		arr.clear();
		int times = 0;

		for (int i = 0, x = 0; ; ++i)
			if (s[i] < '0' || s[i] > '9')
			{
				if (arr.size()) putchar(' ');
				printf("%d", x);

				arr.emplace_back(x), x = 0;
				if (!s[i]) break;
			}
			else x = x * 10 + s[i] - '0';
		
		puts(" ");

		reverse(arr.begin(), arr.end());

		while(true)
		{
			bool done = true;
			int maxx = arr[times], pos = times;

			FOR(i, 1 + times, arr.size())
			{
				if (maxx < arr[i])
					maxx = arr[i], pos = i;
				done &= (arr[i - 1] > arr[i]);
			}
			
			if (done) break;

			reverse(arr.begin() + pos, arr.end());
			reverse(arr.begin() + times, arr.end());


			if (times) putchar(' ');

			if (pos + 1 != arr.size())
				printf("%d %d", pos + 1, times + 1);
			else
				printf("%d", times + 1);

			++times;
		}

		puts((times ? " 0" : "0"));
	}
	return 0;
}
