#include <cstdio>
using namespace std;
int relation[10050];
inline int _find(int p)
{
    if(relation[p]==p) return p;
    else return relation[p]=_find(relation[p]);
}
int main()
{
    for(int N,M,Q;scanf("%d %d %d",&N,&M,&Q)!=EOF;)
    {
        for(int i=1;i<=N;relation[i]=i,i++);
        for(int i=0,a,b;i<M&&scanf("%d %d",&a,&b);relation[_find(a)]=_find(b),i++);
        for(int i=0,a,b;i<Q&&scanf("%d %d",&a,&b);i++)
            if(_find(a)==_find(b)) printf(":)\n");
            else printf(":(\n");
    }
    return 0;
}
