#include <cstdio>
#include <cstring>
using namespace std;
int node[10001];
int main()
{
    int odd_nodes,n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        memset(node,0,sizeof(int)*(n+1));
        odd_nodes=0;
        for(int i=0,a,b;i<m&&scanf("%d %d",&a,&b);i++)
            node[a]++,node[b]++;
        for(int i=1;i<=n;i++)
            if(node[i]&1) {if(odd_nodes>2){break;} odd_nodes++;}
        if(odd_nodes==0||odd_nodes==2) puts("YES");
        else puts("NO");
    }
    return 0;
}
