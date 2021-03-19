#include <bits/stdc++.h>

using namespace std;

int main()
{
    for(unsigned a,b;scanf("%d %d",&a,&b)==2&&a&&b;)
    {
        while(b)
        {
            int _=a%b;
            a=b;
            b=_;
        }
        printf("%u\n",a);
    }
    return 0;
}
