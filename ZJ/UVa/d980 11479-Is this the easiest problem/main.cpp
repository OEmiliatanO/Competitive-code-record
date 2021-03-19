#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T,i=1;
    scanf("%d",&T);
    while(T--)
    {
        long long int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        if(a+b<=c||a+c<=b||c+b<=a)
            printf("Case %d: Invalid\n",i++);
        else if(a==b&&b==c)
            printf("Case %d: Equilateral\n",i++);
        else if(a==b||b==c||a==c)
            printf("Case %d: Isosceles\n",i++);
        else
            printf("Case %d: Scalene\n",i++);
    }
    return 0;
}
