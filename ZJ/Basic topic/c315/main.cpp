#include <cstdio>
using namespace std;
int N,x=0,y=0,a,b;
int main()
{
    scanf("%d",&N);
    while(N--&&scanf("%d %d",&a,&b))
        switch(a)
        {
            case 0:
                y+=b;
                break;
            case 1:
                x+=b;
                break;
            case 2:
                y-=b;
                break;
            case 3:
                x-=b;
                break;
        }
    printf("%d %d",x,y);
    return 0;
}
