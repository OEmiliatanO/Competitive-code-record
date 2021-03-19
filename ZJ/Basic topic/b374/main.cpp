#include <cstdio>
#include <algorithm>
using namespace std;
typedef struct _com
{
    int N,cnt=0;
}com;
com arr[30001];
bool cmp(const com &a,const com &b)
{
    if(a.cnt!=b.cnt) return a.cnt>b.cnt;
    return a.N<b.N;
}
int main()
{
    int n,maxx;
    while(scanf("%d",&n)!=EOF)
    {
        maxx=-1;
        for(int i=0,in;i<n&&scanf("%d",&in);i++)
        {
            arr[in].cnt++;
            arr[in].N=in;
            maxx=max(maxx,in);
        }
        sort(arr,arr+maxx+1,cmp);
        for(int i=0;i<n&&arr[i].cnt==arr[0].cnt;i++)
            printf("%d %d\n",arr[i].N,arr[i].cnt);
    }
    return 0;
}
