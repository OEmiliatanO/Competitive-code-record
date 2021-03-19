#include <cstdio>
#include <cstring>
#define min(x,y) (x)>(y)?(y):(x)
#define max(x,y) (x)>(y)?(x):(y)
using namespace std;
int noise[101][101];
int main()
{
    for(int C,S,Q,C1,C2,kase=1;scanf("%d %d %d",&C,&S,&Q)!=EOF&&(C|S|Q);kase++)
    {
        memset(noise,0x3f,sizeof(noise));
        for(int i=1;i<=C;i++) noise[i][i]=0;
        for(int i=0,d;i<S&&scanf("%d %d %d",&C1,&C2,&d);i++)
            noise[C1][C2]=noise[C2][C1]=d;
        for(int k=1;k<=C;k++)
            for(int i=1;i<=C;i++)
                for(int j=1;j<=C;j++)
                    noise[i][j]=noise[j][i]=min(noise[i][j],max(noise[i][k],noise[k][j]));
        printf("Case #%d\n",kase);
        for(int i=0;i<Q&&scanf("%d %d",&C1,&C2);i++)
            if(noise[C1][C2]>=0x3f3f3f) printf("no path\n");
            else printf("%d\n",noise[C1][C2]);
    }
    return 0;
}
