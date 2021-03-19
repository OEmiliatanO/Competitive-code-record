// e900.cpp

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int MAXN = 1000;

int n;
enum { UnChange, Change };
int contirbute[2][MAXN + 1];

bool dp[2][MAXN * 26 + 1];
int step[2][MAXN * 26 + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	while (cin >> n)
	{
		for (int i = 1, a, b; i <= n; ++i)
		{
			cin >> a >> b;
			contirbute[UnChange][i] = a - b + 13;
			contirbute[Change][i] = b - a + 13;
		}

		memset(dp, false, sizeof(bool) * 2 * (MAXN + 1));
		memset(step, 0x7f, sizeof(int) * 2 * (MAXN + 1));

		dp[0][0] = true;
		step[0][0] = 0;
		for (int i = 1; i <= n; ++i)
		{
			memset(dp[i & 1], false, sizeof(bool) * (MAXN * 26 + 1));
			memset(step[i & 1], 0x7f, sizeof(int) * (MAXN * 26 + 1));

			for (int idx = 0; idx <= 1; ++idx)
				for (int j = n * 26 - 1; j >= contirbute[idx][i]; --j)
					if (dp[(i - 1) & 1][j - contirbute[idx][i]])
					{
						dp[i & 1][j] = true;
						step[i & 1][j] = min(step[i & 1][j], step[(i - 1) & 1][j - contirbute[idx][i]] + idx);
					}
		}

		for (int i = 0; i <= 13 * n; ++i)
			if (dp[n & 1][13 * n - i] || dp[n & 1][13 * n + i])
			{
				cout << min(step[n & 1][13 * n - i], step[n & 1][13 * n + i]) << '\n';
				break;
			}

	}

	return 0;
}
