#include <bits/stdc++.h>

using namespace std;

int main()
{
    for(long int a,b,c;scanf("%lld %lld %lld",&a,&b,&c)==3&&a&&b&&c;)
    {
        long int x=max(a,max(b,c)),x2=(x==a?max(b,c):(x==b?max(a,c):max(a,b)));
        long int _=a+b+c;
        if(_-x>x)
            if(x==a) printf((x2==b?"B\n":"C\n"));
            else if(x==b) printf((x2==a?"A\n":"C\n"));
            else printf((x2==a?"A\n":"B\n"));
        else
            if(x==a) printf("A\n");
            else if(x==b) printf("B\n");
            else printf("C\n");
    }
    return 0;
}
