#include <cstdio>
#include <string.h>
using namespace std;
int color_plate[102][102];
int colorid(char ch)
{
    switch(ch)
    {
        case 'R':
            return 1;
        case 'B':
            return 2;
        case 'Y':
            return 4;
        case 'P':
            return 3;
        case 'O':
            return 5;
        case 'D':
            return 7;
        case 'G':
            return 6;
    }
}
int check(int color,int &color_number,int N)
{
    for(int y=0;y<N;y++)
        for(int x=0;x<N;x++)
            if(color_plate[y][x]==color)
                color_number++;
}
bool inside(int x,int y,int N)
{
    return (x>=0&&x<N&&y>=0&&y<N);
}
int main()
{
    for(int N,Max_area=0;scanf("%d",&N)!=EOF;Max_area=0)
    {
        char ch[2];
        int _X[3],_Y[3],COLOR[3];
        memset(color_plate,0,sizeof(color_plate));

        for(int i=0,x,y;i<3&&scanf("%s %d %d",&ch,&x,&y);i++)
        {
            _X[i]=x;
            _Y[i]=N-y-1;
            COLOR[i]=colorid(ch[0]);
            color_plate[N-y-1][x]=colorid(ch[0])|color_plate[N-y-1][x];
        }
        scanf("%s",&ch);
        int color=colorid(ch[0]);

        for(int t=0,area=0;t<=N;t++,area=0)
        {
            check(color,area,N);
            Max_area=(Max_area<area?area:Max_area);
            for(int i=0;i<3;i++)
            {
                int y=_Y[i],x=_X[i],ty=y-t,dy=y+t,lx=x-t,rx=x+t;
                if(ty<0) ty=0;
                if(dy>=N) dy=N-1;
                if(lx<0) lx=0;
                if(rx>=N) rx=N-1;
                for(int Y=ty;Y<=dy;Y++)
                    for(int X=lx;X<=rx;X++)
                        color_plate[Y][X]|=COLOR[i];
            }
        }
        printf("%d\n",Max_area);
    }
    return 0;
}
