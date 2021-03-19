#include <cstdio>
#define abs(x) (x)<0?~(x)+1:(x)
using namespace std;
int coef[9],i;
bool pos[9];
int main()
{
    while(scanf("%d %d %d %d %d %d %d %d %d",&coef[8],&coef[7],&coef[6],&coef[5],&coef[4],&coef[3],&coef[2],&coef[1],&coef[0])==9)
    {
        i=8;
        while(i>0&&coef[i]==0) i--;
        if(i>0)
        {
            int output=abs(coef[i]);
            if(coef[i]<0) printf("-");
            if(output!=1) printf("%d",output);
            printf("x");
            if(i!=1) printf("^%d",i);
        }
        else
            printf("%d",coef[i]);
        i--;
        for(int output;i>=0;i--)
        {
            output=abs(coef[i]);
            if(output==0) continue;
            printf(coef[i]>0?" + ":" - ");
            if(i>0)
            {
                if(output!=1) printf("%d",output);
                printf("x");
                if(i!=1) printf("^%d",i);
            }
            else
                printf("%d",output);
        }
        puts("");
    }
    return 0;
}
