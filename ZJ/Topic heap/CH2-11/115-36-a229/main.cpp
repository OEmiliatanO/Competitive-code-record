#include <cstdio>
using namespace std;
int n,p=0;
char result[30];

inline void dfs(int l,int r,int cnt)
{
    if(cnt==2*n)
    {
        puts(result);
        return;
    }
    if(l<n)
    {
        result[p++]='(';
        dfs(l+1,r,cnt+1);
        result[--p]=' ';
    }
    if(r<l)
    {
        result[p++]=')';
        dfs(l,r+1,cnt+1);
        result[--p]=' ';
    }
}
int main()
{
    for(;scanf("%d",&n)!=EOF&&n;p=0)
        dfs(0,0,0);
    return 0;
}
