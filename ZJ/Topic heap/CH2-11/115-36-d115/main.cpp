#include <cstdio>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
vector<int> v;
vector<bool> found;
int n,m;
void dfs(int p,int t)
{
    if(t==m)
    {
        for(int i=0;i<n;i++)
            if(found[i]) printf("%d ",v[i]);
        printf("\n");
    }
    else
        for(;p<n;p++)
            if(t<m) {found[p]=true; dfs(p+1,t+1); found[p]=false;}
}
int main()
{
    for(;scanf("%d",&n)!=EOF&&n;)
    {
        v.resize(n);
        found.resize(n);
        for(int i=0;i<n&&scanf("%d",&v[i])!=EOF;found[i]=false,i++);
        scanf("%d",&m);
        sort(v.begin(),v.end());
        dfs(0,0);
        printf("\n");
    }
    return 0;
}
