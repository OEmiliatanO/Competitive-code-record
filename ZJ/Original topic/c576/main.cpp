#include <algorithm>
#include <time.h>
#include <cstdio>
#define RAND_SEED time(0)/60
using namespace std;
const int MAXN=30000;
int N=30000,cnt=N-1,n=0,a[30010],b[30010];
struct cmp
{
    int x;
    cmp(int x):x(x){}
    inline bool operator()(int y)
    {
        return y<x;
    }
};
void hack(int l,int r)
{
    if (r-l<=1) return;
    int c=l+rand()%(r-l),p1=N,p2=N,p=N;
    for(int i=l;i<r;i++)
        if(a[i]==cnt) p=i;
    for(int i=0;i<N;i++)
    {
        if(b[i]==cnt) p1=i;
        if(b[i]==a[c]) p2=i;
    }
    cnt--;
    swap(b[p2],b[p1]);
    swap(a[c],a[p]);
    swap(a[l],a[c]);
    int pivot=stable_partition(a+l+1,a+r,cmp(a[l]))-a;
    swap(a[l],a[pivot-1]);
    hack(l,pivot-1),hack(pivot,r);
}
int main()
{
    unsigned int seed = RAND_SEED;
    srand(seed);
    for(int i=0;i<N;i++) a[i]=b[i]=i;
    hack(0,N);
    printf("%d\n",N);
    for(int i=0;i<N;i++) printf("%d ",b[i]);
    return 0;
}
