#include <cstdio>
#include <cstring>
#include <algorithm>
#define deadline second
#define profit first

using namespace std;

const int MAXN = 10001;
int N, ans, maxi;
int day[MAXN];
pair<int, int> works[MAXN];

int find(int x)
{
    return (day[x] == x ? x : day[x] = find(day[x]));
}

int main()
{
    while(~scanf("%d", &N))
    {
        maxi = ans = 0;

        for(int i = 0; i < N; maxi = max(maxi, works[i].deadline), i++)
            scanf("%d %d", &works[i].deadline, &works[i].profit);
        for(int i = 1; i <= maxi; i++)
            day[i] = i;

        sort(works, works + N, [](const pair<int, int> &a, const pair<int, int> &b){return a.profit > b.profit;});

        for(int i = 0, root; i < N; i++)
        {
            root = find(works[i].deadline);
            if(root)
            {
                ans += works[i].profit;
                day[root] = find(root - 1);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
