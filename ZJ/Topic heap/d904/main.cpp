#include <cstdio>
#include <cstring>
#define min(x,y) ((x)>(y)?(y):(x))
using namespace std;
int C,N;
int main()
{
    int v[11],m[1001];
    memset(m,0x7f,sizeof(int)*1001);
    scanf("%d %d",&C,&N);
    for(int i=0;i<N&&scanf("%d",&v[i]);i++);
    m[0]=0;
    for(int i=0;i<N;i++)
        for(int j=v[i];j<=C;j++)
            m[j]=min(m[j-v[i]]+1,m[j]);
    printf("%d",m[C]);
    return 0;
}
