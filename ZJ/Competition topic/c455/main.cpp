#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAXN=100001;
vector<int> node[MAXN];
int match[MAXN],p,q,k,x,y;
bool vis[MAXN];
inline bool dfs(int i)
{
    for(int j:node[i])
    {
        if(vis[j]==true) continue;
        vis[j]=true;
        if(match[j]<0||dfs(match[j]))
        {
            match[j]=i;
            return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;cin>>n;
    size_t m_size=sizeof(match);
    for(int ans=0;n--&&cin>>p>>q>>k;ans=0)
    {
        memset(match,-1,m_size);
        for(int i=1;i<=p;i++) node[i].clear();
        while(k--&&cin>>x>>y)
            node[x].emplace_back(y);
        for(int i=1;i<=p;i++)
        {
            memset(vis,false,q+1);
            if(dfs(i)) ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
