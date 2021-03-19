#include <cstdio>
#include <cmath>
using namespace std;

bool is_square(int n)
{
    int l=ceil(sqrt(n));
    for(int i=1;i<=l;i++)
        if(i*i==n)
            return true;
    return false;
}

int main()
{
    int M;
    scanf("%d",&M);
    for(int i=0,a,b,c;i<M&&scanf("%d %d %d",&a,&b,&c);i++)
    {
        c=b*b-4*a*c;
        if(c<0)
            printf("No\n");
        else if(is_square(c)||!c)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
