#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int _=1;_<=n-i;_++) printf("_");
        for(int _=1;_<=i;_++) printf("*");
        printf("\n");
    }
    return 0;
}
