#include <cstdio>
#include <algorithm>
using namespace std;
typedef struct _work
{
    double v;
    int i;
}work;
work event[1001];
inline bool cmp(const work &a,const work &b)
{
    if(a.v!=b.v) return a.v<b.v;
    return a.i<b.i;
}
int main()
{
    int T,N;scanf("%d",&T);
    while(T--&&scanf("%d",&N))
    {
        for(int i=0,a,b;i<N&&scanf("%d %d",&a,&b);i++)
        {
            event[i].v=(double)a/b;
            event[i].i=i+1;
        }
        sort(event,event+N,cmp);
        printf("%d",event[0].i);
        for(int i=1;i<N;printf(" %d",event[i].i),i++);
        puts("");
        if(T) puts("");
    }
    return 0;
}
