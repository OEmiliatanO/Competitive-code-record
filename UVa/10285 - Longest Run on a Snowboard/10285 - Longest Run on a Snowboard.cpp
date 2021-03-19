// 10285 - Longest Run on a Snowboard.cpp
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

constexpr int MAXN = 100;
constexpr int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

int n, r, c;

int way[MAXN + 5][MAXN + 5];

int dp[MAXN + 5][MAXN + 5];
string s;

void dfs(int i, int j)
{
	dp[i][j] = 1;
	for (int k = 0; k < 4; ++k)
	{
		int nexi = i + dir[k][0], nexj = j + dir[k][1];
		if (way[nexi][nexj] < way[i][j])
		{
			dfs(nexi, nexj);
			dp[i][j] = max(dp[i][j], dp[nexi][nexj] + 1);
		}
	}
}

int main()
{
	memset(way, 0x7f, sizeof(way));

	cin >> n;

	while (n--)
	{
		memset(dp, -1, sizeof(dp));

		cin >> s >> r >> c;

		for (int i = 1; i <= r; ++i)
			for (int j = 1; j <= c; ++j)
				cin >> way[i][j];

		int ans = -1;
		for (int i = 1; i <= r; ++i)
			for (int j = 1; j <= c; ++j)
			{
				if (dp[i][j] == -1)
					dfs(i, j);
				ans = max(ans, dp[i][j]);
			}

		cout << s << ": " << ans << '\n';
	}
	return 0;
}

/*
2
Feldberg 10 5
56 14 51 58 88
26 94 24 39 41
24 16 8 51 51
76 72 77 43 10
38 50 59 84 81
5 23 37 71 77
96 10 93 53 82
94 15 96 69 9
74 0 62 38 96
37 54 55 82 38
Spiral 5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

*/