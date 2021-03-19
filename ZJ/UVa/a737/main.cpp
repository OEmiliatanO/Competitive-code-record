#include <cstdio>
#include <algorithm>
using namespace std;
int s[500];
int main()
{
    int n;scanf("%d",&n);
    for(int r,sum=0;n--&&scanf("%d",&r);sum=0)
    {
        for(int i=0;i<r&&scanf("%d",&s[i]);i++);
        sort(s,s+r);
        for(int i=0;i<r;sum+=abs(s[r>>1]-s[i]),i++);
        printf("%d\n",sum);
    }
    return 0;
}
