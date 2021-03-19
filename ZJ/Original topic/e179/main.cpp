#include <cstdio>

using namespace std;

int n, k, target, money[20], cnt;
bool flag;

bool dfs(int chos, int nowMoney, int cnt = 0)
{
    ++cnt;
    nowMoney += money[chos];

    if(cnt == k)
        return (nowMoney == target);

    if(nowMoney >= target)
        return false;

    for(int i = chos + 1; i < n; ++i)
        if(dfs(i, nowMoney, cnt))
            return true;

    return false;
}

int main()
{
    while(~scanf("%d %d %d", &n, &k, &target))
    {
        cnt = flag = 0;

        for(int i = 0; i < n; ++i)
            scanf("%d", money + i);

        for(int i = 0; i < n && !flag; ++i)
            flag = dfs(i, 0);

        puts((flag ? "YES" : "NO"));
    }
    return 0;
}
