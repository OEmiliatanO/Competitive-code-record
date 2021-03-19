// 1328E.cpp

#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

constexpr int MAXN = 2e5;

vector<int> G[MAXN + 1];
int query[MAXN + 1];
int n, m;

int pa[MAXN + 1];
int dep[MAXN + 1];
int Tin[MAXN + 1], Tout[MAXN + 1], T = 0;
void dfs(int now = 1, int p = -1, int dept = 0)
{
    pa[now] = p, dep[now] = dept;
    Tin[now] = T++;
    for (auto it : G[now])
    {
        if (it == p) continue;
        dfs(it, now, dept + 1);
    }
    Tout[now] = T++;
}

int main()
{
    cin >> n >> m;

    for (int i = 0, u, v; i < n - 1; ++i)
    {
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs();

    for (int i = 0, j; i < m; ++i)
    {
        cin >> j;

        bool flag = true;
        pair<int, int> node = {-1, -1};
        for (int k = 0; k < j; ++k)
        {
            cin >> query[k];
            node = max(node, { dep[query[k]], query[k] });
            if (query[k] == 1) continue;
            query[k] = pa[query[k]];
        }

        int u = node.second;
        for (int k = 0; k < j; ++k)
            flag &= (Tin[u] >= Tin[query[k]] && Tout[u] <= Tout[query[k]]);

        if (flag)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}