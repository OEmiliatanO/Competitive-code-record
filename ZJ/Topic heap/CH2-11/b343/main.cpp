#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> Dominos[10001];
vector<bool> down(10001);
int cnt=0;
void dfs(int x)
{
    if(down[x]) return;
    down[x]=true;
    cnt++;
    for(int i=0;i<Dominos[x].size();i++)
        dfs(Dominos[x][i]);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int n,m,l,now,next,push;T--&&scanf("%d %d %d",&n,&m,&l)==3;cnt=0)
    {
        fill(down.begin(),down.begin()+n,false);
        for(int i=0;i<=n;i++) Dominos[i].clear();
        for(int i=0;i<m&&scanf("%d %d",&now,&next);i++) Dominos[now].push_back(next);
        for(int i=0;i<l&&scanf("%d",&push);i++) dfs(push);
        printf("%d\n",cnt);
    }
    return 0;
}
