#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 20001;
struct br
{
    int H, W, id;
}beaver[MAXN];

int T, N, M, nowH, nowW;
vector<br> ans;

int main()
{
    scanf("%d", &T);
    while(T-- && scanf("%d %d", &N, &M))
    {
        ans.clear();

        for(int i = 1; i <= N; beaver[i].id = i, i++)
            scanf("%d %d", &beaver[i].H, &beaver[i].W);

        ans.emplace_back(beaver[M]);
        nowH = beaver[M].H, nowW = beaver[M].W;
        sort(beaver + 1, beaver + 1 + N, [&](const br a, const br b) -> bool {return (a.H < b.H) || (a.H == b.H && a.W < b.W);});

        for(int i = 1; i <= N; i++)
        {
            while(ans.size() && ans.back().H < beaver[i].H && ans.back().W < beaver[i].W)
                ans.pop_back();
            if(nowH < beaver[i].H && nowW < beaver[i].W)
                ans.emplace_back(beaver[i]);
        }

        sort(ans.begin(), ans.end(), [&](const br a, const br b) -> bool {return a.id < b.id;});

        printf("%d\n", ans.size());
        for(auto it : ans)
            printf("%d ", it.id);
        puts("");
    }
    return 0;
}
