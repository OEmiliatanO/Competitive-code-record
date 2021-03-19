#include <cstdio>
#include <string.h>
using namespace std;
int a[5002],b[5002],c[5002],cnt=1,n;
bool found[5002];
void dfs(int s)
{
    for(int i=1;i<=n;i++)
        if(!found[i]&&a[i]<a[s]&&c[i]<b[s]) {cnt++; found[i]=true; dfs(i);}
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int s;T--&&scanf("%d",&n)&&n>0;cnt=1)
    {
        memset(found,false,sizeof(found));
        for(int i=1;i<=n&&scanf("%d %d %d",&a[i],&b[i],&c[i])!=EOF;i++);
        scanf("%d",&s);
        found[s]=true;
        dfs(s);
        printf("%d\n",cnt);
    }
    return 0;
}
