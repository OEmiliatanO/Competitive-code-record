#include <cstdio>
#include <cstring>
#include <algorithm>
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
typedef struct num_
{
    int N,cnt=0;
}num;
inline bool cmp(const num &a,const num &b)
{
    if(a.cnt!=b.cnt) return a.cnt>b.cnt;
    return a.N<b.N;
}
int main()
{
    num a[10];
    for(int n,maxx=-1;scanf("%d",&n)!=EOF;maxx=-1,puts(""))
    {
        for(int i=0;i<10;a[i].N=i,a[i].cnt=0,i++);
        for(int i=0,x;i<n&&scanf("%d",&x);a[x].cnt++,i++);
        sort(a,a+10,cmp);
        for(int i=0;i<10&&a[i].cnt!=0;i++) printf("%d ",a[i].N);
    }
    return 0;
}
