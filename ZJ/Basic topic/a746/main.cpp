#include <cstdio>
#include <cstring>
using namespace std;
bool area[501][501];
int main()
{
    for(int n,m,x=-1,y=-1;scanf("%d %d",&n,&m)!=EOF;x=-1,y=-1)
    {
        memset(area,false,sizeof(area));
        for(int i=0,x1,y1;i<m&&scanf("%d %d",&x1,&y1);x=x1,y=y1,i++)
            if(x==x1)
            {
                for(int j=y;j<=y1&&y<=y1;area[x][j]=true,j++);
                for(int j=y;j>=y1&&y>=y1;area[x][j]=true,j--);
            }
            else if(y==y1)
            {
                for(int j=x;j<=x1&&x<=x1;area[j][y]=true,j++);
                for(int j=x;j>=x1&&x>=x1;area[j][y]=true,j--);
            }
        for(int i=0;i<n+2;i++) putchar('-');
        puts("");
        for(int i=1;i<=n;i++)
        {
            putchar('|');
            for(int j=1;j<=n;j++)
                putchar((area[i][j]?'*':' '));
            putchar('|');
            puts("");
        }
        for(int i=0;i<n+2;i++) putchar('-');
        puts("");
    }
    return 0;
}
