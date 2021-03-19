#include <bits/stdc++.h>

using namespace std;

int main()
{
    for(int n;scanf("%d",&n)==1&&n;)
    {
        if(n==1) break;
        for(int i=1;i<n;i++) if(i%7) printf("%d ",i);
        printf("\n");
    }
    return 0;
}
