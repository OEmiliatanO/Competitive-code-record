#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
struct edge_
{
    int from, to, wi;
}edge[101];
int dij[12], n, m, edgeCnt, totCost;
set<pair<int,int> > ans;
set<int> nodeCnt;
bool cmp(const edge_ &a, const edge_ &b)
{
    return (a.wi < b.wi);
}
inline int find(int x)
{
    return (dij[x] == x ? x : dij[x] = find(dij[x]));
}
int main()
{
    while(~scanf("%d %d", &n, &m) && getchar())
    {
        totCost = edgeCnt = 0;
        ans.clear();
        for(int i = 1; i <= n; i++)
            dij[i] = i;
        for(int f, t, w; edgeCnt < m; edgeCnt++)
        {
            getchar();scanf("%d", &f);
            getchar();getchar();scanf("%d", &t);
            getchar();scanf("%d", &w);getchar();
            nodeCnt.emplace(f);nodeCnt.emplace(t);
            edge[edgeCnt].from = f, edge[edgeCnt].to = t, edge[edgeCnt].wi = w;
        }
        sort(edge, edge + edgeCnt, cmp);
        n = nodeCnt.size();
        for(int i = 0, r1, r2; i < edgeCnt && ans.size() < n - 1; i++)
        {
            r1 = find(edge[i].from);
            r2 = find(edge[i].to);
            if(r1 != r2)
            {
                totCost += edge[i].wi;
                ans.emplace(edge[i].from, edge[i].to);
                dij[r1] = r2;
                find(r1);
            }
        }
        for(auto it : ans)
            printf("(W%d W%d) ", it.first, it.second);
        putchar('\n');
        printf("%d\n",totCost);
    }
    return 0;
}
