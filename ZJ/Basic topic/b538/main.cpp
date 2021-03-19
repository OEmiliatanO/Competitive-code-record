#include <cstdio>
#include <algorithm>
#define fit(a,b) if((a)<0) {(b)=~(b)+1; (a)=~(a)+1;}
using namespace std;
int a,b,c,d;
char sy;
int main()
{
    for(;scanf("%d %d %d %d %c",&a,&b,&c,&d,&sy)!=EOF&&b&&d;)
    {
        fit(b,a);
        fit(d,c);
        int lcm=b*d/__gcd(b,d),gcd;
        if(sy=='+'||sy=='-')
        {
            a*=lcm/b;
            c*=lcm/d;
            if(sy=='+') a+=c;
            else a-=c;
            b=lcm;
        }
        else if(sy=='*') a*=c,b*=d;
        else a*=d,b*=c;
        gcd=__gcd(a,b);
        a/=gcd,b/=gcd;
        if(a==b||a==0||b==1) printf("%d",a/b);
        else
        {
            fit(b,a);
            printf("%d/%d",a,b);
        }
        putchar('\n');
    }
    return 0;
}
