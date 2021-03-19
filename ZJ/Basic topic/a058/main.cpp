#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,N3=0,N1=0,N2=0;
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        if(x%3==0) N3++;
        else if(x%3==1) N1++;
        else if(x%3==2) N2++;
    }
    printf("%d %d %d",N3,N1,N2);
    return 0;
}
