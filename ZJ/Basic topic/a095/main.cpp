#include <iostream>

using namespace std;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2&&m&&n)
        printf("%d\n",(n==m?m:m+1));
    return 0;
}
