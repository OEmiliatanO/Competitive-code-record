#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
vector<LL> v;
LL cnt=0;
void merge_sort(vector<LL> &v,int l,int r,vector<LL> &T)
{
    if(r-l>1)
    {
        int m=l+(r-l)/2;
        int p=l,q=m,i=l;
        merge_sort(v,l,m,T);
        merge_sort(v,m,r,T);
        while(p<m||q<r)
            if(q>=r||(p<m&&v[p]<=v[q])) T[i++]=v[p++];
            else {T[i++]=v[q++],cnt+=m-p;}
        for(i=l;i<r;i++) v[i]=T[i];
    }
}
int main()
{
    for(int n;scanf("%d",&n)!=EOF&&n;cnt=0)
    {
        v.resize(n);
        vector<LL> T(n);
        LL in;
        for(int i=0;i<n&&scanf("%lld",&in);v[i]=in,i++);
        merge_sort(v,0,n,T);
        printf("%lld\n",cnt);
    }
    return 0;
}
