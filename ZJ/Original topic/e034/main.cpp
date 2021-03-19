#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=51;
const bool left=1,right=1,up=0,down=0;
struct obj
{
    int val=0;
    bool dir=0;
};
obj DP[MAXN][MAXN];
int money[MAXN][MAXN],N,ans;
int main()
{
    while(~scanf("%d",&N))
    {
        ans=0;
        for(int i=0,m;i<N;i++)
            for(int j=0;j<N&&scanf("%d",&m);j++)
                money[i][j]=m;
        //DP 1 from 0,0 to N-1,N-1
        DP[0][0].val=money[0][0];
        for(int j=1;j<N;j++)
        {
            DP[0][j].val=DP[0][j-1].val+money[0][j];
            DP[0][j].dir=left;
        }
        for(int i=1;i<N;i++)
            for(int j=0;j<N;j++)
            {
                int UP=money[i][j]+DP[i-1][j].val;
                int LEFT=money[i][j]+DP[i][j-1].val;
                if(j-1<0||UP>LEFT)
                {
                    DP[i][j].val=UP;
                    DP[i][j].dir=up;
                }
                else
                {
                    DP[i][j].val=LEFT;
                    DP[i][j].dir=left;
                }
            }
        ans+=DP[N-1][N-1].val;
        int tmpi=N-1,tmpj=N-1;
        while(tmpi>=0&&tmpj>=0)
        {
            money[tmpi][tmpj]=0;
            if(DP[tmpi][tmpj].dir==up) tmpi--;
            else tmpj--;
        }

        //DP 2 from N-1,N-1 to 0,0
        DP[N-1][N-1].val=0;
        for(int j=N-2;j>=0;j--)
        {
            DP[N-1][j].val=DP[N-1][j+1].val+money[N-1][j];
        }
        for(int i=N-2;i>=0;i--)
            for(int j=N-1;j>=0;j--)
            {
                int DOWN=money[i][j]+DP[i+1][j].val;
                int RIGHT=money[i][j]+DP[i][j+1].val;
                if(j+1>=N||DOWN>RIGHT)
                {
                    DP[i][j].val=DOWN;
                }
                else
                {
                    DP[i][j].val=RIGHT;
                }
            }
        ans+=DP[0][0].val;
        printf("%d\n",ans);
    }
    return 0;
}
