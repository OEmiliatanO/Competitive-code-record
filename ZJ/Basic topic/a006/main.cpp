#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF)
    {
        int D=b*b-4*a*c;
        if(D>0)
            printf("Two different roots x1=%d , x2=%d\n",(int)(sqrt(D)-b)/(2*a),(int)(-b-sqrt(D))/(2*a));
        else if(D==0)
            printf("Two same roots x=%d\n",(-b)/(2*a));
        else
            puts("No real root");
    }
    return 0;
}
