// 1325F.cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

constexpr int MAXN = 1e5;

int n, m, sq;
vector<int> G[MAXN + 1];

int marked[MAXN + 1];
enum{ Undefine = -1, Unchosen = 0, Chosen };
int st[MAXN + 1], head = 0, tail = 0;
int dep[MAXN + 1]{};
void dfs(int now = 1, int fa = 0)
{
    dep[now] = dep[fa] + 1;

    st[tail++] = now;

    for (auto nex : G[now])
    {
        if (!dep[nex])
            dfs(nex, now);
        else if (dep[now] - dep[nex] + 1 >= sq)
        {
            cout << "2\n" << dep[now] - dep[nex] + 1 << '\n';
            while (st[tail - 1] != nex)
                cout << st[--tail] << ' ';
            cout << st[--tail];
            exit(0);
        }
    }

    if (marked[now] == Undefine)
    {
        marked[now] = Chosen;
        for (auto nex : G[now])
            marked[nex] = Unchosen;
    }

    tail--;
}

int main()
{
    cin >> n >> m;

    memset(marked, -1, sizeof(int) * (MAXN + 1));

    sq = 1;
    while (sq * sq < n)
        ++sq;

    for (int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs();

    cout << "1\n";
    for (int i = 1; i <= n && sq; ++i)
        if (marked[i] == Chosen)
        {
            cout << i << ' ';
            --sq;
        }

    return 0;
}
