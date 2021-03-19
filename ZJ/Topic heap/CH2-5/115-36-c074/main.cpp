#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t=0;
    for(int k;scanf("%d",&k)==1&&k;t++)
    {
        if(t) printf("\n");
        vector<int> LN(k);
        for(int i=0;i<k;i++)
            scanf("%d",&LN[i]);
        for(int i=0;i<k;i++)
            for(int j=i+1;j<k;j++)
                for(int m=j+1;m<k;m++)
                    for(int n=m+1;n<k;n++)
                        for(int a=n+1;a<k;a++)
                            for(int b=a+1;b<k;b++)
                                printf("%d %d %d %d %d %d\n",LN[i],LN[j],LN[m],LN[n],LN[a],LN[b]);
    }
    return 0;
}
