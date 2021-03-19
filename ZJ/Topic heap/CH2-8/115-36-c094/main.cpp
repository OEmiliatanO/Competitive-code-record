#include <bits/stdc++.h>
using namespace std;
vector<int> device;
vector<bool> OPEN;
int main()
{
    for(int n,m,c,T=1;scanf("%d %d %d",&n,&m,&c)!=EOF&&n&&m&&c;T++)
    {
        if(T!=1) printf("\n");
        int nowI=0,highestI=-1;
        bool burned=false;
        device.resize(n+1);
        OPEN.resize(n+1);
        for(int i=1;i<=n;OPEN[i]=false,i++);

        for(int i=1;i<=n&&scanf("%d",&device[i]);i++);

        for(int i=0,in;i<m&&scanf("%d",&in);i++)
        {
            if(OPEN[in])
            {
                OPEN[in]=false;
                nowI-=device[in];
            }
            else
            {
                OPEN[in]=true;
                nowI+=device[in];
            }
            if(nowI>c)
                burned=true;
            highestI=(highestI<nowI?nowI:highestI);
        }
        if(burned)
            printf("Sequence %d\nFuse was blown.\n",T);
        else
            printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n",T,highestI);

    }
    return 0;
}
