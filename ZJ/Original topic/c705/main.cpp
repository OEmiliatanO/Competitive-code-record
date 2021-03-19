#include <cstdio>
using namespace std;
int IP[4];
int main()
{
    for(int n;scanf("%d",&n)!=EOF;IP[0]=IP[1]=IP[2]=IP[3]=0)
    {
        for(int i=3;i>=0;i--)
            for(int j=0,pow=1;j<8;n=n>>1,j++,pow*=2)
                IP[i]=IP[i]+(n&1)*pow;
        printf("%d.%d.%d.%d\n",IP[0],IP[1],IP[2],IP[3]);
    }
    return 0;
}
