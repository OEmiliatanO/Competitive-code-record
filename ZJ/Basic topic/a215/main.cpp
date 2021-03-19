#include <cstdio>

using namespace std;

int main()
{
    for(int n,m;scanf("%d %d",&n,&m)!=EOF;)
    {
        int t=1;
        for(int x=n+1,sum=n;sum<=m;sum+=x,x++,t++);
        printf("%d\n",t);
    }
    return 0;
}
