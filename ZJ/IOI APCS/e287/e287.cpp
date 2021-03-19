#pragma warning( disable : 4996 )
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

const int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int n, m, sti, stj, mini = 1000001;
int Mp[103][103];
bool vis[103][103];
long long ans = 0;
queue<pii> qu;

int main()
{
	memset(Mp, 0x7f, sizeof(int) * 103 * 103);
	memset(vis, false, 103 * 103);

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			scanf("%d", &Mp[i][j]);
			if (mini > Mp[i][j])
				sti = i, stj = j, mini = Mp[i][j];
		}

	qu.emplace(pii{ sti, stj });

	while (qu.size())
	{
		int nowi = qu.front().first, nowj = qu.front().second, di = -1, dj = -1;
		ans += Mp[nowi][nowj];
		vis[nowi][nowj] = true;
		mini = 1000001;
		qu.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nexi = nowi + dir[i][0], nexj = nowj + dir[i][1];
			if (mini > Mp[nexi][nexj] && !vis[nexi][nexj])
				di = nexi, dj = nexj, mini = Mp[nexi][nexj];
		}
		if (di > 0 && dj > 0)
			qu.emplace(pii{ di,dj });
	}

	printf("%lld", ans);

	return 0;
}
