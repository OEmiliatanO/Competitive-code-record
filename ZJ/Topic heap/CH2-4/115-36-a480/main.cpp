#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct City
{
    int a,b;
}city[1000005];

bool cmp(struct City A,struct City B)
{
    return A.a<B.a;
}
int main()
{
    int n,X1,X2,Y1,Y2;;
    while(scanf("%d %d %d %d",&X1,&Y1,&X2,&Y2)==4)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            city[i].a=(x-X1)*(x-X1)+(y-Y1)*(y-Y1);
            city[i].b=(x-X2)*(x-X2)+(y-Y2)*(y-Y2);
        }
        sort(city,city+n,cmp);
        for(int i=n-2;i>=0;i--)
        {
            city[i].b=(city[i].b>city[i+1].b?(city[i].b):(city[i+1].b));
        }
        int ans=2147483647;
        for(int i=0;i<n;i++)
        {
            int p=city[i].a,tmp=0;
            if(i!=n-1) {tmp=city[i+1].b;}
            p+=tmp;
            ans=(ans<p?ans:p);
        }
        ans=(ans<city[0].b?(ans):(city[0].b));
        printf("%d\n",ans);
    }
    return 0;
}
