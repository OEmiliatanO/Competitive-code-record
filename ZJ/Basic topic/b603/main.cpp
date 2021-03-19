#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    for(long long x1,y1,x2,y2;scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2)!=EOF;)
    {
        long long a,b,c,d,gcd;
        a=y2-y1;
        b=-2*x1*a;
        d=(x2-x1)*(x2-x1);
        c=a*x1*x1+d*y1;
        gcd=__gcd(a,b),gcd=__gcd(gcd,c),gcd=__gcd(gcd,d);
        printf("%lldy = %lldx^2 + %lldx + %lld\n",d/gcd,a/gcd,b/gcd,c/gcd);
    }
    return 0;
}
