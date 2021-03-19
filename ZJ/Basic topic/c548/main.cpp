#include <cstdio>
#include <algorithm>
#include <vector>
#define num first
#define index second

using namespace std;

const int MAXN = 1e5 + 1;
int n, k, x;
pair<int, int> arr[MAXN];
vector<int> ans;

bool dfs(int now, int nowk)
{
    if(arr[now].num > nowk) return false;

    nowk -= arr[now].num;

    if(nowk == 0) return true;

    for(int i = now + 1; i <= n; i++)
        if(arr[i].num > nowk) return false;
        else if(dfs(i, nowk))
        {
            ans.emplace_back(arr[i].index);
            return true;
        }
}

int main()
{
    scanf("%d %d", &n ,&k);
    for(int i = 1; i <= n && scanf("%d", &arr[i].num); ++i)
    {
        arr[i].num %= k;
        arr[i].index = i;
    }

    sort(arr + 1, arr + 1 + n);

    dfs(0, k);

    printf("%d\n", ans.size());
    for(auto it : ans)
        printf("%d ", it);

    return 0;
}
