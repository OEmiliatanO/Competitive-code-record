#include <cstdio>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f
#define in(x,y,m,n) (x)>=1&&(x)<=m&&(y)>=1&&(y)<=n
using namespace std;
typedef struct _Node
{
    int x,y,wi;
    _Node(){}
    _Node(int x,int y,int wi):x(x),y(y),wi(wi){}
    bool operator<(const _Node &a)const {return wi>a.wi;}
}Node;
Node Temp;
int T,Maze[1000][1000],dis[1000][1000],dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
bool vis[1000][1000];
int main()
{
    scanf("%d",&T);
    for(int N,M,all;T--&&scanf("%d%d",&N,&M);)
    {
        priority_queue<Node> heap;
        all=N*M;
        memset(vis,false,sizeof(vis));
        memset(dis,0x3f,sizeof(dis));
        for(int y=1;y<=N;y++)
            for(int x=1;x<=M&&scanf("%d",&Maze[y][x]);x++)
        dis[1][1]=Maze[1][1];
        heap.push(Node(1,1,dis[1][1]));
        for(int i=0,next_x=-1,next_y=-1;i<all;i++,next_x=-1,next_y=-1)
        {
            while(!heap.empty())
            {
                Temp=heap.top(),heap.pop();
                if(!vis[Temp.y][Temp.x])
                {
                    next_x=Temp.x;
                    next_y=Temp.y;
                    break;
                }
            }
            if(next_x==-1||(next_x==M&&next_y==N))
                break;
            vis[next_y][next_x]=true;
            for(int j=0;j<4;j++)
            {
                int x=next_x+dir[j][0],y=next_y+dir[j][1];
                if(in(x,y,M,N)&&dis[next_y][next_x]+Maze[y][x]<dis[y][x])
                {
                    dis[y][x]=dis[next_y][next_x]+Maze[y][x];
                    heap.push(Node(x,y,dis[y][x]));
                }
            }
        }
        printf("%d\n",dis[N][M]);
    }
    return 0;
}
