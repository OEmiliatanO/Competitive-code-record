#include <cstdio>
#include <string.h>
using namespace std;
typedef long long LL;
LL pow(LL a,LL n)
{
    if(n==1)
        return a;
    else if(n%2)
    {
        LL T=pow(a,(n-1)/2);
        return T*T*a;
    }
    else
    {
        LL T=pow(a,n/2);
        return T*T;
    }
}
int main()
{
    for(LL a,n;scanf("%lld",&a)!=EOF;)
    {
        char str[1000];
        if(a==1||a==-1)
        {
            scanf("%s",&str);
            if(a==1)
                printf("1\n");
            else if((str[strlen(str)-1]-'0')%2)
                printf("-1\n");
            else
                printf("1\n");
            continue;
        }
        scanf("%lld",&n);
        if(a==0&&n==0) {printf("All Over.");break;}
        if(a==0)
            printf("0\n");
        else if(n==0||a==1)
            printf("1\n");
        else
            printf("%lld\n",pow(a,n));
    }
    return 0;
}
