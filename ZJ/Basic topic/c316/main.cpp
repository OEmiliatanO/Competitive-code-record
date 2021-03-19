#include <cstdio>
#include <cmath>
using namespace std;
typedef struct _point
{
    int x,y;
}point;
point POINT[1000];
int p=1;
double getdis(const point &a,const point &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    point now;
    int a,b;
    double maxdis=0,dis;
    for(int N,x,y;scanf("%d",&N)!=EOF;maxdis=0,p=1)
    {
        scanf("%d %d",&x,&y);
        POINT[0].x=x,POINT[0].y=y;
        for(int i=1;i<N&&scanf("%d %d",&x,&y);i++)
        {
            POINT[i].x=x,POINT[i].y=y,p++;
            for(int j=0;j<p;j++)
            {
                dis=getdis(POINT[i],POINT[j]);
                if(dis>maxdis) a=i,b=j,maxdis=dis;
            }
        }
        if(a<b) printf("%d %d\n",a,b);
        else printf("%d %d\n",b,a);
    }
    return 0;
}
