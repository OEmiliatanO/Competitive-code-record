#include <cstdio>
#include <queue>
using namespace std;
const bool Origin=0,Vis=1;
const int MAXN=515;
int I,J,W,E,N,S,area;
bool place[2][MAXN][MAXN]{};
void bfs(int i,int j)
{
    int yi,xj;
    queue<pair<int,int> > qu;
    qu.emplace(make_pair(i,j));
    while(qu.size())
    {
        yi=qu.front().first,xj=qu.front().second; qu.pop();
        if(place[Vis][yi][xj]) continue;
        area++;
        place[Vis][yi][xj]=true;
        if(xj<W) W=xj;
        else if(xj>E) E=xj;
        if(yi<N) N=yi;
        else if(yi>S) S=yi;
        if(place[Origin][yi-1][xj]&&!place[Vis][yi-1][xj])
            qu.emplace(make_pair(yi-1,xj));
        if(place[Origin][yi+1][xj]&&!place[Vis][yi+1][xj])
            qu.emplace(make_pair(yi+1,xj));
        if(place[Origin][yi][xj-1]&&!place[Vis][yi][xj-1])
            qu.emplace(make_pair(yi,xj-1));
        if(place[Origin][yi][xj+1]&&!place[Vis][yi][xj+1])
            qu.emplace(make_pair(yi,xj+1));
    }
}
int main()
{
    scanf("%d %d",&J,&I);
    for(int i=1,x;i<=I;i++)
        for(int j=1;j<=J&&scanf("%d",&x);j++)
            place[Origin][i][j]=x;
    for(int i=1;i<=I;i++)
        for(int j=1;j<=J;j++)
            if(place[Origin][i][j]&&!place[Vis][i][j])
            {
                W=E=j;
                N=S=i;
                area=0;
                bfs(i,j);
                printf("%d %d %d %d %d\n",W-1,N-1,E-1,S-1,area);
            }
    return 0;
}
