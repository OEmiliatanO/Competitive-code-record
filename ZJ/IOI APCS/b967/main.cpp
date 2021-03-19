#include <cstdio>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
const int MAXN=100002;
vector<int> tree[MAXN];
bool father_[MAXN];
int inner_max=0;
int dfs(int);
int main()
{
    for(int N;scanf("%d",&N)!=EOF&&N;inner_max=0)
    {
        int root=-1,from_root;
        memset(father_,false,sizeof(father_));
        for(int i=0;i<N;tree[i].clear(),i++);
        for(int a,b,i=1;i<=N-1&&scanf("%d %d",&a,&b)==2;i++)
        {
            father_[b]=true;
            tree[a].push_back(b);
        }
        for(int i=0;i<N;i++)
            if(!father_[i]){root=i;break;}
        from_root=dfs(root);
        printf("%d\n",(inner_max>from_root?inner_max:from_root));
    }
    return 0;
}
int dfs(int now)
{
    if(now<0) return -1;
    int now_size=tree[now].size();
    if(!now_size) return 0;
    else
    {
        priority_queue<int,vector<int>,greater<int> > pq;
        for(int i=0;i<now_size;i++)
        {
            int result=dfs(tree[now][i])+1;
            pq.push(result);
            if(pq.size()>2)
                pq.pop();
        }
        if(pq.size()==1)
            inner_max=(pq.top()>inner_max?pq.top():inner_max);
        else
        {
            int _=pq.top();
            pq.pop();
            inner_max=(pq.top()+_>inner_max?pq.top()+_:inner_max);
        }
        return pq.top();
    }
}
