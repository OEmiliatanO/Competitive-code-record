#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        int sum=0,Achieve=59*n;
        for(int _=0,x;_<n&&scanf("%d",&x)==1;_++)
            sum+=x;
        printf((sum>Achieve?"no\n":"yes\n"));
    }
    return 0;
}
