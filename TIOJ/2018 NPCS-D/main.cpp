#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long int64;
typedef struct _node
{
    int64 s,p;
}node;
int main()
{
    node temp;
    for(int n,k,p=0;scanf("%d %d",&n,&k)!=EOF;p=0)
    {
        int64 Size[n+5],Price[n+5],small=2e9+1;
        node v[n+5];
        for(int i=0;i<n&&scanf("%lld",&Size[i]);i++);
        for(int i=0;i<n&&scanf("%lld",&Price[i]);i++);
        for(int i=0;i<n;i++)
            if(Size[i]>k)
                small=min(small,Price[i]);
            else if(Size[i]==k)
            {
                small=0;
                break;
            }
            else
            {
                temp.s=Size[i];
                temp.p=Price[i];
                v[p++]=temp;
            }

        if(small!=0)
            for(int i=0;i<p&&small!=0;i++)
                for(int j=i+1;j<p;j++)
                    if(v[i].s+v[j].s==k) {small=0; break;}
                    else if(v[i].s+v[j].s>k) small=min(small,min(v[i].p,v[j].p));
        printf("%lld\n",(small==2e9+1?-1:small));
    }
    return 0;
}
