#include <cstdio>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    double sum=0;
    for(int n,in;T--&&scanf("%d",&n);sum=0)
    {
        for(int i=0;i<n&&scanf("%d",&in);sum+=in,i++);
        printf("%.2f\n",sum/n);
    }
    return 0;
}
