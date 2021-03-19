// 1325E.cpp
#pragma warning( disable : 4996 )
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <unordered_map>
#include <utility>
#include <cassert>
#include <cstring>

using namespace std;

using int64 = long long;
using pii = pair<int, int>;

constexpr int MAXN = 1e6 + 200;

int n;
int arr[MAXN + 1];
int ans = INT_MAX;

unordered_map<int, bool> mp;

int eid = 1;
vector<pii> G[MAXN + 1];

void regulate(int x)
{
    int p = 1, q = 1;
    for (int i = 2, num; i * i <= x; ++i)
    {
        num = 0;
        while (x % i == 0)
        {
            x /= i;
            ++num;
        }
        if (num & 1)
            if (q == 1) q = i;
            else        p = i;
    }
    
    if (q == 1) q = x;
    else if (p == 1) p = x;

    if (p == 1 && q == 1)
    {
        ans = 1;
        return;
    }
    if (mp[p * q])
    {
        ans = min(2, ans);
        return;
    }
    mp[p * q] = true;

    G[p].emplace_back(q, eid);
    G[q].emplace_back(p, eid);
    ++eid;
}

int dis[MAXN + 1];
bool visEdge[MAXN + 1];
int bfs(int root)
{
    memset(dis, -1, sizeof(int) * (MAXN + 1));
    memset(visEdge, false, sizeof(bool) * (MAXN + 1));

    assert(eid <= MAXN + 1);

    dis[root] = 0;

    queue<int> qu;
    qu.emplace(root);

    while (!qu.empty())
    {
        int now = qu.front(); qu.pop();
        for (auto nex : G[now])
        {
            int to = nex.first, edgeId = nex.second;

            if (visEdge[edgeId]) continue;

            if (dis[to] == -1)
            {
                dis[to] = dis[now] + 1;
                visEdge[edgeId] = true;
                qu.emplace(to);
            }
            else return dis[to] + dis[now] + 1;
        }
    }

    return INT_MAX;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &x);
        regulate(x);
    }

    if (ans == 1 || ans == 2)
    {
        printf("%d", ans);
        return 0;
    }

    for (int i = 1; i <= 1000; ++i)
        ans = min(ans, bfs(i));

    printf("%d", (ans == INT_MAX ? -1 : ans));

    return 0;
}
