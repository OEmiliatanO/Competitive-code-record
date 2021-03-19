#include <bits/stdc++.h>

using namespace std;

struct statue
{
    int number;
    int h,w;
};

bool Compare(statue A,statue B)
{
    if(A.h!=B.h)
        return A.h<B.h;
    else if(A.w!=B.w)
        return A.w<B.w;
    else
        return A.number<B.number;
}

int main()
{
    int n;
    while(cin>>n)
    {
        statue Statues[n+1];

        for(int i=1;i<=n;i++)
        {
            int X;
            Statues[i].number=i;
            scanf("%d",&X);
            Statues[i].h=X;
            scanf("%d",&X);
            Statues[i].w=X;
        }
        sort(Statues+1,Statues+1+n,Compare);

        /*for(int i=1;i<=n;i++)
        {
            int X;
            printf("Statues[%d].number=%d\n",i,Statues[i].number);
            printf("%d ",Statues[i].h);
            printf("%d\n",Statues[i].w);
            Statues[i].w=X;
        }*/
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=abs(i-Statues[i].number);
        }
        printf("%d\n",sum);
    }
    return 0;
}
