#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int T,N,s1,v1,s2,v2,maxx=-100000;
    scanf("%d",&T);
    for(int t=0,k=1;t<T;t++,maxx=-100000,k++)
    {
        scanf("%d %d %d %d %d",&N,&s1,&v1,&s2,&v2);
        for(int i=0;i<=N/s1;i++)
            for(int j=0;j<=N/s2;j++)
                if(s1*i+s2*j<=N) maxx=(maxx<v1*i+v2*j?v1*i+v2*j:maxx);
                else break;
        printf("Case #%d: %d\n",k,maxx);
    }
    return 0;
}
