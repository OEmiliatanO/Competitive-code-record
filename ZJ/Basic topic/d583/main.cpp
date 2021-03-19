#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int v[100000];
int main()
{
    for(int n;scanf("%d",&n)!=EOF;)
    {
        for(int i=0;i<n&&scanf("%d",&v[i])!=EOF;i++);
        sort(v,v+n);
        for(int i=0;i<n;i++)
            printf("%d ",v[i]);
        printf("\n");
    }
    return 0;
}
