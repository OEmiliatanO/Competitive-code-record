#include <cstdio>
#include <cmath>
using namespace std;
int _x,_y,queen[8],soulTime=0;
inline bool IsOK(int x,int y,int putx,int puty)
{
    if(y==puty||x==putx) return false;
    else if(y+abs(putx-x)==puty||y-abs(putx-x)==puty) return false;
    return true;
}
void dfs(int x)
{
    if(x==_x)
        dfs(x+1);
    else if(x==8)
        printf(" %d      %d %d %d %d %d %d %d %d\n",++soulTime,queen[0],queen[1],queen[2],queen[3],queen[4],queen[5],queen[6],queen[7]);
    else
        for(int y=1;y<=8;y++)
        {
            bool OK=true;
            if(!IsOK(_x,_y,x,y)) OK=false;
            else
                for(int i=0;i<x;i++)
                    if(!IsOK(i,queen[i],x,y)) {OK=false; break;}
            if(OK)
            {
                queen[x]=y;
                dfs(x+1);
            }
        }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(;T&&scanf("%d %d",&_y,&_x)!=EOF&&_x&&_y;T--,soulTime=0)
    {
        printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
        queen[--_x]=_y;
        dfs(0);
        printf("\n");
    }
    return 0;
}
