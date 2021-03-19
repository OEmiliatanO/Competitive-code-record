#include <bits/stdc++.h>

using namespace std;

typedef struct _point
{
    int x,y;
}point;
double GetDis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    for(int N,m;scanf("%d %d",&N,&m)!=EOF&&N&&m;)
    {
       point P[m];
       double MIN=1<<30;
       for(int i=0,x,y;i<m&&scanf("%d %d",&x,&y)==2;i++)
       {
           P[i].x=x;
           P[i].y=y;
       }
       for(int i=0;i<m;i++)
            for(int j=i+1;j<m;j++)
            {
                double _=GetDis(P[i],P[j]);
                MIN=(MIN>_?_:MIN);
            }
        printf("%.4f\n",MIN);
    }
    return 0;
}
