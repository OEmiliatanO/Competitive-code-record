#include <cstdio>
using namespace std;
const short R=0,L=1,U=2,D=3;
int out[300][300];
short n,offset,cnt,dir,offsetClock,turnClock,nowi,nowj;
int main()
{
    while(~scanf("%hd",&n))
    {
        if(n==1) {puts("0"); continue;}
        cnt=offset=1;
        offsetClock=out[n][n]=turnClock=0;
        nowi=nowj=n;
        dir=R;
        while(cnt<=n*n-1)
        {
            if(offsetClock==2)
            {
                offsetClock=0;
                offset++;
            }
            for(int i=0;i<offset;i++)
                if(dir==R)
                {
                    out[nowi][++nowj]=cnt++;
                }
                else if(dir==L)
                {
                    out[nowi][--nowj]=cnt++;
                }
                else if(dir==U)
                {
                    out[--nowi][nowj]=cnt++;
                }
                else if(dir==D)
                {
                    out[++nowi][nowj]=cnt++;
                }
            if(dir==R) dir=U;
            else if(dir==L) dir=D;
            else if(dir==U) dir=L;
            else dir=R;
            offsetClock++;
        }
        for(int i=n-(n>>1);i<=n+(n>>1);putchar('\n'),i++)
            for(int j=n-(n>>1);j<=n+(n>>1);j++)
                printf("%4d",out[i][j]);
    }
    return 0;
}
