#include <cstdio>
#include <string.h>
#include <set>
using namespace std;
int tree[105];
set<int> record;
set<int>::iterator it;
bool cycle(int n,int root)
{
    if(n==root) return false;
    int now=tree[n];
    while(true)
    {
        if(now==root) return false;
        else if(now==n) return true;
        now=tree[now];
    }
}
int main()
{
    for(int a,b,k=1;scanf("%d %d",&a,&b)!=EOF&&a>=0&&b>=0;k++,record.clear())
    {
        if(a==0&&b==0) {printf("Case %d is a tree.\n",k); continue;}
        int root=-1;
        bool is_a_tree=true;
        memset(tree,-1,sizeof(tree));
        tree[b]=a;
        record.insert(a),record.insert(b);
        for(;scanf("%d %d",&a,&b)!=EOF&&(a||b);)
        {
            if(tree[b]==-1) tree[b]=a;
            else is_a_tree=false;
            record.insert(a),record.insert(b);
        }
        if(!is_a_tree) {printf("Case %d is not a tree.\n",k); continue;}
        for(it=record.begin();it!=record.end();it++)
            if(tree[*it]==-1)
                if(root==-1) root=*it;
                else is_a_tree=false;
        if(!is_a_tree||root==-1) {printf("Case %d is not a tree.\n",k); continue;}
        for(it=record.begin();it!=record.end()&&is_a_tree;it++)
            if(cycle(*it,root)) is_a_tree=false;
        if(is_a_tree) printf("Case %d is a tree.\n",k);
        else printf("Case %d is not a tree.\n",k);
    }
    return 0;
}
