#include <cstdio>
using namespace std;
int main()
{
    int arr[50];
    for(int n,Max,sum;scanf("%d",&n)!=EOF;)
    {
        for(int i=0;i<n&&scanf("%d",&sum);arr[i]=sum,i++);
        Max=sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum<0) sum=0;
            Max=(sum>Max?sum:Max);
        }
        printf("%d\n",Max);
    }
    return 0;
}
