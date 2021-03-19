#include <cstdio>
#include <vector>
using namespace std;
vector<int> v;
int cnt=0;
void merge_sort(vector<int> &v,int l,int r,vector<int> &T)
{
    if(r-l>1)
    {
        int m=l+((r-l)>>1);
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
    for(int n;~scanf("%d",&n)&&n;cnt=0)
    {
        v.resize(n);
        vector<int> T(n);
        for(int i=0,in;i<n&&scanf("%d",&in);v[i]=in,i++);
        merge_sort(v,0,n,T);
        puts((cnt&1?"Marcelo":"Carlos"));
    }
    return 0;
}
