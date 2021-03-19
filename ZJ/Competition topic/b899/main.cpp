#include <cstdio>
using namespace std;
int x1,y1,x2,y2,x3,y3;
int a,b,c;
int main()
{
    scanf("%d %d",&x1,&y1);
    scanf("%d %d",&x2,&y2);
    scanf("%d %d",&x3,&y3);
    a=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    b=(x2-x3)*(x2-x3)+(y2-y3)*(y2-y3);
    c=(x1-x3)*(x1-x3)+(y1-y3)*(y1-y3);
    if(a>b&&a>c) printf("%d %d",x1+x2-x3,y1+y2-y3);
    else if(b>c&&b>a) printf("%d %d",x2+x3-x1,y2+y3-y1);
    else printf("%d %d",x1+x3-x2,y1+y3-y2);
    return 0;
}
