#include <cstdio>
using namespace std;
bool bits[33];
int v,a,b;
int main()
{
    while(~scanf("%d %d %d",&v,&a,&b))
    {
        for(int i=0;i<32;bits[i]=v&1,v>>=1,i++);
        bits[a]=b;
        for(int i=31;i>=0;i--) putchar(bits[i]+'0');
        puts("");
    }
    return 0;
}
