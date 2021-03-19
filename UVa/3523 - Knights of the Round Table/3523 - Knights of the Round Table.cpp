// 3523 - Knights of the Round Table.cpp
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

using pii = pair<int, int>;

constexpr int MAXN = 1e3;

int n, m;
bool hate[MAXN + 1][MAXN + 1];
vector<int> G[MAXN + 1];

stack<pii> st;
vector<int> bccWith[MAXN + 1];
int low[MAXN + 1], depth[MAXN + 1];
int bcc[MAXN + 1], NBcc;
void dfs(int now = 1, int fa = 0)
{
    low[now] = depth[now] = depth[fa] + 1;

    for (auto nex : G[now])
    {
        if (nex == fa)
            continue;

        if (!depth[nex])
        {
            st.emplace(now, nex);
            dfs(nex, now);
            low[now] = min(low[now], low[nex]);

            if (low[nex] >= depth[now])
            {
                while (!st.empty())
                {
                    pii E = st.top(); st.pop();
                    if (bcc[E.first] != NBcc) bccWith[NBcc].emplace_back(E.first), bcc[E.first] = NBcc;
                    if (bcc[E.second] != NBcc) bccWith[NBcc].emplace_back(E.second), bcc[E.second] = NBcc;

                    if (E.first == now && E.second == nex)
                        break;
                }
                ++NBcc;
            }
        }
        else if (depth[nex] < depth[now])
        {
            st.emplace(now, nex);
            low[now] = min(low[now], depth[nex]);
        }
    }

}

int color[MAXN + 1];
bool isBi(int now, int nowBcc)
{
    for (auto nex : G[now])
    {
        if (bcc[nex] != nowBcc) continue;

        if (color[nex] == color[now])
            return false;
        if (color[nex] == -1)
        {
            color[nex] = !color[now];
            if (!isBi(nex, nowBcc))
                return false;
        }
    }
    return true;
}

bool isExile[MAXN + 1];
void init()
{
    st = stack<pii>();
    memset(hate, false, sizeof(bool) * (MAXN + 1) * (MAXN + 1));
    NBcc = 1;
    
    for (int i = 0; i <= MAXN; ++i)
    {
        G[i].clear();
        bccWith[i].clear();
        bcc[i] = depth[i] = 0;
        isExile[i] = true;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n >> m, n | m)
    {
        init();

        for (int i = 0, u, v; i < m; ++i)
        {
            cin >> u >> v;
            hate[u][v] = true;
            hate[v][u] = true;
        }

        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (!hate[i][j])
                {
                    G[i].emplace_back(j);
                    G[j].emplace_back(i);
                }

        for (int i = 1; i <= n; ++i)
            if (!depth[i])
                dfs(i, 0);

        for (int i = 1; i < NBcc; ++i)
        {
            for (auto now : bccWith[i])
            {
                bcc[now] = i;
                color[now] = -1;
            }

            color[*bccWith[i].begin()] = 0;
            if (!isBi(*bccWith[i].begin(), i))
                for (auto now : bccWith[i])
                    isExile[now] = false;
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i)
            ans += isExile[i];

        cout << ans << '\n';
    }

    return 0;
}
/*
6 8
4 2
6 3
4 1
5 1
5 2
2 6
2 1
3 2

5 5
1 4
1 5
2 5
3 4
4 5

5 0

*/