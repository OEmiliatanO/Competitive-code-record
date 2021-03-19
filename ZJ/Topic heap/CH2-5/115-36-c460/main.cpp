#include <bits/stdc++.h>

using namespace std;

int main()
{
    for(int N;scanf("%d",&N)!=EOF&&N;)
    {
        int Army[4][10];
        long long ans=0;
        memset(Army,0,sizeof(Army));
        for(int i=0,in1,in2,in3,in4;i<N;i++)
        {
            scanf("%d %d %d %d",&in1,&in2,&in3,&in4);
            Army[in1][in2*4+in3*2+in4]++;
        }
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                for(int k=0;k<8;k++)
                    if((i|j|k)==7)
                        ans+=Army[1][i]*Army[2][j]*Army[3][k];
        printf("%lld\n",ans);
    }
    return 0;
}
