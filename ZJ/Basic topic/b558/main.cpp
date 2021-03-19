#include <cstdio>
using namespace std;
typedef long long int64;
int64 N[501]={0,1};
int main()
{
    for(int i=2;i<501;N[i]=N[i-1]+i-1,i++);
    for(int n;scanf("%d",&n)!=EOF;)
        printf("%lld\n",N[n]);
    return 0;
}
