#include <cstdio>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
vector<int> DAG[101];
int father[101];
int main()
{
    for(int n,m,now;scanf("%d %d",&n,&m)!=EOF;)
    {
        priority_queue<int,vector<int>,greater<int> > qu;
        memset(father,0,sizeof(father));
        for(int i=0;i<n;DAG[i].clear(),i++);
        for(int t=0,i,j;t<m&&scanf("%d %d",&i,&j);DAG[i].push_back(j),father[j]++,t++);
        for(int i=0;i<n;i++)
            if(father[i]==0) qu.push(i);
        while(!qu.empty())
        {
            now=qu.top(),qu.pop();
            printf("%d ",now);
            for(int i=0;i<DAG[now].size();i++)
                if(--father[DAG[now][i]]==0)
                    qu.push(DAG[now][i]);
        }
        printf("\n");
    }
    return 0;
}
