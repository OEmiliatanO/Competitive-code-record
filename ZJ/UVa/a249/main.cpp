#include <cstdio>
using namespace std;
int main()
{
    int n;scanf("%d",&n);
    for(int k=1,D,I;n--&&scanf("%d %d",&D,&I);k=1)
    {
        I--;
        while(--D)
            k=(k<<1)+(I&0x1),I>>=1;
        printf("%d\n",k);
    }
    return 0;
}
