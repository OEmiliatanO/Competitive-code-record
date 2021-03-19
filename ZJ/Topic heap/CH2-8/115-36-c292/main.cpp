#include <cstdio>

using namespace std;
int N;
int arr[50][50];
int cnt;
void go(int dire,int &x,int &y,int &dx,int &dy)
{
    if(dire==0)
    {
        cnt+=dx;
        for(int i=1;i<=dx;i++)
            printf("%d",arr[y][x--]);
        dx++;
    }
    else if(dire==1)
    {
        cnt+=dy;
        for(int i=1;i<=dy;i++)
            printf("%d",arr[y--][x]);
        dy++;
    }
    else if(dire==2)
    {
        cnt+=dx;
        for(int i=1;i<=dx;i++)
            printf("%d",arr[y][x++]);
        dx++;
    }
    else
    {
        cnt+=dy;
        for(int i=1;i<=dy;i++)
            printf("%d",arr[y++][x]);
        dy++;
    }
}

int main()
{
    for(int dire;scanf("%d",&N)!=EOF&&N;cnt=0)
    {
        int dx=1,dy=1,x=N/2,y=x;
        scanf("%d",&dire);
        for(int y=0;y<N;y++)
            for(int x=0;x<N&&scanf("%d",&arr[y][x]);x++);
        go(dire,x,y,dx,dy);
        while(cnt<N*N)
            go(((++dire)%4),x,y,dx,dy);
        printf("\n");
    }
    return 0;
}
