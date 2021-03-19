#include <cstdio>
#include <string.h>
#include <set>
using namespace std;
int tree[105];
bool father[105];
set<int> record,res_set;
bool find_root(int n)
{
    if(tree[n]!=-1)
        if(!res_set.count(n)) {res_set.insert(n); return find_root(tree[n]);}
        else
            return false;
    else return true;
}
int main()
{
    for(int a,b,k=1;scanf("%d %d",&a,&b)!=EOF&&a>=0&&b>=0;k++)
    {
        if(a==0&&b==0) {printf("Case %d is a tree.\n",k); continue;}
        record.clear();
        memset(tree,-1,sizeof(tree));
        memset(father,false,sizeof(father));
        int root=0;
        bool a_tree=true;
        father[b]=true;
        tree[b]=a;
        record.insert(a),record.insert(b);
        for(int i,j;scanf("%d %d",&i,&j)!=EOF&&(i|j);)
        {
            if(tree[j]==-1) tree[j]=i;
            else a_tree=false;
            if(!father[j]) father[j]=true;
            else a_tree=false;
            record.insert(i),record.insert(j);
        }
        for(set<int>::iterator it=record.begin();it!=record.end();it++)
        {
            res_set.clear();
            if(!find_root(*it)) a_tree=false;
            else root++;
        }
        printf("r=%d\n",root);
        if(root!=1) a_tree=false;
        if(a_tree) printf("Case %d is a tree.\n",k);
        else printf("Case %d is not a tree.\n",k);
    }
    return 0;
}
