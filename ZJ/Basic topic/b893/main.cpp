#include <cstdio>
using namespace std;
typedef long long int64;
int64 a,b,c,d,e,f,tmp1,tmp2;
bool have_root;
int main()
{
    while(~scanf("%lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&e,&f))
    {
        if(a==b&&b==c&&c==d&&d==e&&e==f&&f==0)printf("Too many... = =\"\n");
        else
        {
            have_root=false;
            tmp1=tmp2=0;
            for(int64 x=-73;x<74;x++)
            {
                tmp2=tmp1;
                tmp1=(int64)a*x*x*x*x*x+b*x*x*x*x+c*x*x*x+d*x*x+e*x+f;
                if((tmp1>0&&tmp2<0)||(tmp1<0&&tmp2>0)||tmp1==0)
                {
                    tmp1=(int64)a*x*x*x*x*x+b*x*x*x*x+c*x*x*x+d*x*x+e*x+f;
                    have_root=true;
                    printf("%lld %lld\n",(tmp1==0?x:x-1),x);
                }
            }
            if(!have_root) puts("N0THING! >\\\\\\<");
        }
    }
    return 0;
}
