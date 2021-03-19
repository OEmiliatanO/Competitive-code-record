#include <cstdio>
using namespace std;
typedef long long LL;
LL P[201];
int main()
{
    P[0]=1;
    for(int i=1;i<=200;i++)
        for(int j=i;j<=200;j++)
            P[j]+=P[j-i];
    for(int n;scanf("%d",&n)!=EOF;)
        printf("%lld\n",P[n]);
    return 0;
}
