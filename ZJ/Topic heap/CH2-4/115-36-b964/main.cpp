#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int Num[101]={0};
        for(int i=0;i<n;i++)
        {
            int X;
            scanf("%d",&X);
            Num[X]++;
        }

        for(int i=0;i<101;)
        {
            while(i<101&&!Num[i])
            {
                i++;
            }
            for(int j=1;j<=Num[i]&&i<101;j++)
            {
                printf("%d",i);
                if(j!=Num[i])
                    printf(" ");
            }
            i++;
            while(i<101&&!Num[i])
            {
                i++;
            }
            if(i<101)
                printf(" ");
        }
        printf("\n");
        int Wrost=60,Best=59;
        bool WrostCase=true,BestCase=true;

        while(--Wrost>=0&&!Num[Wrost]);
        if(Wrost>=0&&Num[Wrost])
            BestCase=false;
        while(++Best<101&&!Num[Best]);
        if(Best<101&&Num[Best])
            WrostCase=false;

        if(Wrost>=0)
            printf("%d\n",Wrost);
        if(WrostCase)
            printf("worst case\n");

        if(BestCase)
            printf("best case\n");
        if(Best<101)
            printf("%d\n",Best);
    }
    return 0;
}
