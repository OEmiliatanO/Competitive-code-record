#include <bits/stdc++.h>


using namespace std;
typedef struct XY
{
    int x,y;
}Point;

bool cmp(Point A,Point B)
{
    if(A.x!=B.x) {return A.x<B.x;}
    return A.y<B.y;
}

int main()
{
    int n,i=0;
    scanf("%d",&n);
    Point points[n];
    while(i<n)
    {
        scanf("%d %d",&points[i].x,&points[i].y);
        i++;
    }
    sort(points,points+n,cmp);
    for(i=0;i<n;i++)
    {
        printf("%d %d\n",points[i].x,points[i].y);
    }
    return 0;
}
