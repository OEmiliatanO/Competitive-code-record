#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=1001,INF=900;
int N,M,K,w[MAXN],v[MAXN];
double res[MAXN],sum;
bool cmp(const double &a,const double &b)
{
    return a>b;
}
bool isOK(const double &x)
{
    for(int i=0;i<N;i++)
        res[i]=v[i]-x*w[i];
    sort(res,res+N,cmp);
    sum=0;
    for(int i=0;i<K;i++)
        sum+=res[i];
    return (sum>=0);
}
double getAns()
{
    double l=0,r=INF,mid;
    for(int i=0;i<24;i++)
    {
        mid=(l+r)/2;
        if(isOK(mid)) l=mid;
        else r=mid;
    }
    return l;
}
int main()
{
    scanf("%d %d",&N,&M);
    for(int i=0;i<N&&scanf("%d %d",&w[i],&v[i]);i++);
    for(int i=0;i<M&&scanf("%d",&K);i++)
        printf("%.2f\n",getAns());
    return 0;
}
