// 1220E.cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

using int64 = long long;

constexpr int MAXN = 2e5;

int n, m;
int w[MAXN + 1];
vector<int> G[MAXN + 1];

stack<int> st;
int low[MAXN + 1], dep[MAXN + 1]{};
int bcc[MAXN + 1], Nbcc = 1;
bool existLoop[MAXN + 1]{};
void dfs(int now, int fa)
{
    low[now] = dep[now] = dep[fa] + 1;
    st.emplace(now);

    for (auto nex : G[now])
    {
        if (nex == fa)
            continue;

        if (dep[nex])
            low[now] = min(low[now], dep[nex]);
        else
        {
            dfs(nex, now);
            low[now] = min(low[now], low[nex]);
        }
    }

    if (low[now] == dep[now])
    {
        int child = 0;
        while (!st.empty())
        {
            int x = st.top(); st.pop();
            bcc[x] = Nbcc;
            ++child;

            if (x == now) break;
        }
        existLoop[Nbcc] = (child >= 3);
        ++Nbcc;
    }
}

vector<int> treeG[MAXN + 1];
int64 wi[MAXN + 1];
bool vis[MAXN + 1]{};
void contract(int now)
{
    wi[bcc[now]] += w[now];
    vis[now] = true;

    for (auto nex : G[now])
    {
        if (vis[nex]) continue;

        if (bcc[nex] != bcc[now])
        {
            treeG[bcc[now]].emplace_back(bcc[nex]);
            treeG[bcc[nex]].emplace_back(bcc[now]);
        }

        contract(nex);
    }
}

int64 dp[MAXN + 1][2]{};
void treedp(int now, int fa)
{
    dp[now][0] += wi[now];
    for (auto nex : treeG[now])
    {
        if (nex == fa)
            continue;

        treedp(nex, now);

        if (existLoop[nex])
        {
            existLoop[now] = true;
            dp[now][0] += dp[nex][0];
        }
        else
            dp[now][1] = max(dp[now][1], dp[nex][1]);
    }

    dp[now][1] += dp[now][0];

    for (auto nex : treeG[now])
    {
        if (nex == fa)
            continue;

        if (existLoop[nex])
            dp[now][1] = max(dp[now][1], dp[now][0] + dp[nex][1] - dp[nex][0]);
    }
}

int root;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        cin >> w[i];

    for (int i = 1, u, v; i <= m; ++i)
    {
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    cin >> root;

    dfs(root, 0);

    contract(root);

    treedp(bcc[root], 0);

    cout << dp[bcc[root]][1] << '\n';

    return 0;
}
