#include <cstdio>
using namespace std;
int main()
{
    int n,t;
    while(~scanf("%d",&n))
    {
        for(t=0;n!=1;t++)
            if(n&1) n=n*3+1;
            else n>>=1;
        printf("%d\n",t);
    }
    return 0;
}
