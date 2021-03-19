#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int64;
int64 arr[1000000];
int main()
{
    for(int N;scanf("%d",&N)!=EOF;)
    {
        for(int i=0;i<N&&scanf("%lld",&arr[i]);i++);
        sort(arr,arr+N);
        if(arr[0]<=0)
            for(int i=0;i<N-1;arr[N-1]+=abs(arr[i]),i++);
        else
        {
            for(int i=1;i<N-1;i++)
                arr[0]-=arr[i];
            arr[N-1]-=arr[0];
        }
        printf("%lld\n",arr[N-1]);
    }
    return 0;
}
