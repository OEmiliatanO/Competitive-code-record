// a764-1.cpp

#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

constexpr int MAXN = 400;

int64_t G[MAXN + 1][MAXN + 1];
int64_t dis[MAXN + 1][MAXN + 1];
int64_t ans = INT64_MAX;
int n, m;
int64_t k;

int main()
{
    memset(dis, 0x3f, sizeof(dis));
    memset(G, 0x3f, sizeof(G));

    cin >> n >> m;
    for (int i = 0, a, b; i < m; ++i)
    {
        cin >> a >> b >> k;
        G[a][b] = G[b][a] = dis[a][b] = dis[b][a] = min(dis[a][b], k);
    }

    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i < k; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
                if (G[i][k] != 0x3f3f3f3f3f3f3f3f and G[k][j] != 0x3f3f3f3f3f3f3f3f)
                    ans = min(ans, dis[i][j] + G[i][k] + G[k][j]);
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    if (ans == INT64_MAX)
        cout << "No solution." << '\n';
    else
        cout << ans << '\n';

    return 0;
}
