#include <cstdio>
#include <algorithm>
#define S first
#define R second
using namespace std;
const int MAXN=100001;
typedef long long int64;
pair<int,int> obj[MAXN];
int b[MAXN];
int k,m;
int64 merge_sort(int l,int r)
{
    int64 res=0;
    if(l<r)
    {
        int mid=(l+r)>>1;
        res=merge_sort(l,mid)+merge_sort(mid+1,r);
        for(int i=l,j=mid+1,k=l;i<=mid||j<=r;k++)
            if(j==r+1||i<=mid&&obj[i].R<=obj[j].R) b[k]=obj[i++].R;
            else
            {
                b[k]=obj[j++].R;
                res+=mid-i+1;
            }
        for(int i=l;i<=r;i++) obj[i].R=b[i];
    }
    return res;
}
int main()
{
    scanf("%d %d",&k,&m);
    for(int i=0;i<k;i++) scanf("%d",&obj[i].S);
    for(int i=0;i<k;i++) scanf("%d",&obj[i].R);
    sort(obj,obj+k);
    printf("%lld",merge_sort(0,k-1));
    return 0;
}
