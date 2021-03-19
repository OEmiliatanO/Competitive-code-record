#include <cstdio>
#include <algorithm>
using namespace std;
typedef struct com
{
    int m[200];
}_arr;
_arr arr[10010];
int n,m;
bool cmp(const _arr &a,const _arr &b)
{
    for(int i=0;i<m;i++)
        if(a.m[i]!=b.m[i])
            return a.m[i]<b.m[i];
}
int main()
{
    for(;scanf("%d %d",&n,&m)!=EOF;)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m&&scanf("%d",&arr[i].m[j]);j++);
        sort(arr,arr+n,cmp);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                printf("%d ",arr[i].m[j]);
            putchar('\n');
        }
    }
    return 0;
}
