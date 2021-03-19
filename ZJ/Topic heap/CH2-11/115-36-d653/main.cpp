#include <iostream>
#include <algorithm>
using namespace std;
int n,m,v[105],ans[105];

void dfs(int,int);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>m&&(n||m))
    {
        for(int i=0;i<n&&cin>>v[i];i++);
        sort(v,v+n);
        dfs(0,0);
    }
    return 0;
}
inline void dfs(int t,int p)
{
    if(t==m)
    {
        for(int i=0;i<m;i++)
            cout<<ans[i]<<' ';
        cout<<'\n';
    }
    else
    {
        int last=-1;
        for(int i=p;i<n;i++)
            if(m-t>n-p) return;
            else if(v[i]!=last)
            {
                last=v[i];
                ans[t]=v[i];
                dfs(t+1,i+1);
            }
    }
}
