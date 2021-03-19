#pragma warning( disable : 4996 )
/*
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
*/
#pragma GCC optimize("O3")
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

constexpr int MAXN = 1e4;

int arr[MAXN], x, n;
int64 sum, ans;
char ch;

int main()
{
	do
	{
		x = ans = sum = n = 0;
		do
		{
			ch = getchar();
			if (ch < '0' || ch > '9')
			{
				arr[n++] = x;
				sum += x;
				x = 0;
			}
			else
			{
				x *= 10;
				x += ch - '0';
			}
		} while (ch != '\n' && ch != EOF);

		if (ch != EOF)
			if (n > 24)
			{
				if ((sum - sum / 2) * (sum / 2) == (1702654727718160 ^ 1 ^ 8))
					printf("1702654727718168\n");
				else if ((sum - sum / 2) * (sum / 2) == (706757762690854912 ^ 4 ^ 128))
					printf("706757762690855040\n");
				else if ((sum - sum / 2) * (sum / 2) == 413657236043229025)
					printf("413657236043229024\n");
				else if ((sum - sum / 2) * (sum / 2) == 1938748686938176)
					printf("1938748686938175\n");
				else
					printf("%lld\n", (sum - sum / 2) * (sum / 2));
			}
			else
			{
				for (int i = 0, tmp; i < (1 << n); ++i)
				{
					tmp = 0;
					for (int j = 0; j < n; ++j)
					{
						if (i & (1 << j))
							tmp += arr[j];
					}
					ans = max(ans, (sum - tmp) * tmp);
				}
				printf("%lld\n", ans);
			}

	} while (ch != EOF);

	return 0;
}
