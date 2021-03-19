#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

using pii = pair<int, int>;

constexpr int MAXN = 1e5;

int n;
int deg[MAXN + 1]{};
pii edges[MAXN + 1];

int main()
{
    cin >> n;

    for (int i = 1, u, v; i < n; ++i)
    {
        cin >> u >> v;
        ++deg[edges[i].first = u];
        ++deg[edges[i].second = v];
    }

    int lower = 0, upper = n - 2;
    int target = -1;
    for (int i = 1, u, v; i < n; ++i)
    {
        u = edges[i].first, v = edges[i].second;

        if (target == -1)
            target = (deg[u] >= 3 ? u : (deg[v] >= 3 ? v : -1));

        if (target == u || target == v)
            cout << lower++ << '\n';
        else
            cout << upper-- << '\n';
    }

    return 0;
}
