#include <cstdio>
#define abs(x) ((x)<0?(~(x)+1):(x))
using namespace std;
typedef long long int64;
int64 diex,diey,capx,capy,range,px,py;
int main()
{
    while(~scanf("%lld %lld %lld %lld %lld",&diex,&diey,&capx,&capy,&range))
    {
        px=abs(diex-capx);
        py=abs(diey-capy);
        if(px+py<=range) puts("die");
        else puts("alive");
    }
    return 0;
}
