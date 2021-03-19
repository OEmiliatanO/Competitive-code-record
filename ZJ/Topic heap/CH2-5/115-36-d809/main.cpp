#include <bits/stdc++.h>

using namespace std;
typedef struct _POINT
{
    int x,y;
}point;

double TriArea(point A,point B,point C)
{
    return abs(0.50*(A.x*B.y + B.x*C.y + A.y*C.x - A.y*B.x - B.y*C.x - A.x*C.y));
}
int main()
{
    for(int N;scanf("%d",&N)!=EOF&&N;)
    {
       point _P[N];
       for(int i=0;i<N;i++) scanf("%d %d",&_P[i].x,&_P[i].y);
       double Max=-1.0;
       for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
            for(int m=j+1;m<N;m++)
            {
                double _=TriArea(_P[i],_P[j],_P[m]);
                Max=(_>Max?_:Max);
            }
        printf("%.2f\n",Max);
    }
    return 0;
}
