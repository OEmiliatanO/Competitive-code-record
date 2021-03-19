#include <cstdio>
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
int n,ans;
bool arr[7][7],vis[7][7]{};
void dfs(int i,int j,int step)
{

    if(i<0||j<0||i>=n||j>=n) {ans=max(ans,step-1); return;}
    if(!arr[i][j]||vis[i][j]) ans=max(ans,step-1);
    else
    {
        vis[i][j]=true;
        dfs(i-1,j,step+1);
        dfs(i+1,j,step+1);
        dfs(i,j-1,step+1);
        dfs(i,j+1,step+1);
        vis[i][j]=false;
    }

}
int main()
{
    ans=-1;
    scanf("%d",&n);getchar();
    for(int i=0,t;i<n;getchar(),i++)
        for(int j=0;j<n;arr[i][j]=t-'0',j++)
            t=getchar();
    dfs(0,0,1);
    printf("%d",ans);
    return 0;
}
