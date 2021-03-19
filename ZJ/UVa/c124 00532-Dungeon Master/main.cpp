#include <cstdio>
#include <queue>
#include <cstring>
#define in(x,y,z) ((x)>=0&&(x)<L&&(y)>=0&&(y)<R&&(z)>=0&&(z)<C)
using namespace std;
const short Block=-2,Undefine=-1;
const short dir[2]={-1,1};
int L,R,C;
int space[30][30][30],sx,sy,sz,ex,ey,ez;
struct point {int x,y,z;};
void bfs()
{
    queue<point> qu;
    if(space[sx][sy][sz]==Block) {puts("Trapped!"); return;}
    space[sx][sy][sz]=0;
    qu.emplace(point{sx,sy,sz});
    while(qu.size())
    {
        int x=qu.front().x,y=qu.front().y,z=qu.front().z; qu.pop();
        int nexx,nexy,nexz;
        if(x==ex&&y==ey&&z==ez) break;
        for(int index=0;index<3;index++)
            for(int i=0;i<2;i++)
            {
                nexx=x,nexy=y,nexz=z;
                if(index==0) nexx+=dir[i];
                else if(index==1) nexy+=dir[i];
                else if(index==2) nexz+=dir[i];
                if(in(nexx,nexy,nexz)&&space[nexx][nexy][nexz]!=Block&&space[nexx][nexy][nexz]==Undefine)
                {
                    space[nexx][nexy][nexz]=space[x][y][z]+1;
                    qu.emplace(point{nexx,nexy,nexz});
                }
            }

    }
    if(space[ex][ey][ez]==Undefine) puts("Trapped!");
    else printf("Escaped in %d minute(s).\n",space[ex][ey][ez]);
}
int main()
{
    while(~scanf("%d %d %d",&L,&R,&C)&&getchar()&&(L||R||C))
    {
        memset(space,Undefine,sizeof(int)*30*30*30);
        for(int x=0,ch;x<L;getchar(),x++)
            for(int y=0;y<R;getchar(),y++)
                for(int z=0;z<C&&(ch=getchar());z++)
                    if(ch=='#') space[x][y][z]=Block;
                    else if(ch=='S') sx=x,sy=y,sz=z;
                    else if(ch=='E') ex=x,ey=y,ez=z;
        bfs();
    }
    return 0;
}
