#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
char Maze[101][101];
int dis[101][101];
bool vis[101][101];
int W,L,Len,si,sj,Fire;
int dirx[]={0,0,1,-1};
int diry[]={1,-1,0,0};
int main()
{
    while(~scanf("%d %d %d",&W,&L,&Len)&&getchar())
    {
        Fire=0;
        memset(vis,false,sizeof(vis));
        memset(dis,-1,sizeof(dis));
        queue<pii> qu;
        char ch;
        for(int i=0;i<L;(ch=getchar()),i++)
            for(int j=0;j<W;j++)
            {
                ch=getchar();
                Maze[i][j]=ch;
                if(Maze[i][j]=='S') si=i,sj=j;
                else if(Maze[i][j]=='F') Fire++;
            }
        qu.emplace(make_pair(si,sj));
        dis[si][sj]=1;
        while(qu.size())
        {
            int ni=qu.front().first,nj=qu.front().second;
            int nexi,nexj;
            qu.pop();
            for(int i=0;i<4;i++)
            {
                nexi=ni+dirx[i],nexj=nj+diry[i];
                if(nexi<0||nexi>=L||nexj<0||nexj>=W||Maze[nexi][nexj]=='#'||dis[ni][nj]+1>Len||vis[nexi][nexj]) continue;
                if(Maze[nexi][nexj]=='F') Fire--;
                vis[nexi][nexj]=true;
                dis[nexi][nexj]=dis[ni][nj]+1;
                qu.emplace(make_pair(nexi,nexj));
            }
        }
        for(int i=0;i<L;putchar('\n'),i++)
            for(int j=0;j<W;j++)
                if(Maze[i][j]=='#') putchar('#');
                else if(dis[i][j]!=-1) putchar('.');
                else putchar(Maze[i][j]);
        puts("");
        if(Fire==0) puts("All Fires Extinguished!");
    }

    return 0;
}
