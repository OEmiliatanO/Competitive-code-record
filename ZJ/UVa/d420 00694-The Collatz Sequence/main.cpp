#include <cstdio>
using namespace std;
typedef long long int64;
int A,L,t=1;
int64 a;
int cnt()
{
    int ans=1;
    a=A;
    while(a!=1)
    {
        if(a&1) a=3*a+1;
        else a>>=1;
        if(a>L) break;
        ans++;
    }
    return ans;
}
int main()
{
    while(~scanf("%d %d",&A,&L)&&(A>0||L>0))
        printf("Case %d: A = %d, limit = %d, number of terms = %d\n",t++,A,L,cnt());
    return 0;
}
