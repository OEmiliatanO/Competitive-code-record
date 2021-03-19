#include <cstdio>
using namespace std;
int n,p;
bool ans[33];
int main()
{
    while(~scanf("%d",&n)&&n)
    {
        p=0;
        while(n!=0)
            ans[p++]=n&1,n>>=1;
        for(int i=p-1;i>=0;i--) putchar(ans[i]+'0');
        puts("");
    }
    return 0;
}
