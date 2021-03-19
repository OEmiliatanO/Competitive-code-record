#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned int uint;
const int MAXN=100001;
uint N,Q,K,p,q,arr[MAXN];
int main()
{
    scanf("%u %u",&N,&Q);
    for(uint i=0;i<N&&scanf("%u",&arr[i]);i++);
    sort(arr,arr+N);
    for(uint i=0;i<Q&&scanf("%u",&K);i++)
    {
        p=0,q=1;
        while(arr[q]-arr[p]!=K&&q<N&&p<N)
            if(arr[q]-arr[p]>K) p++;
            else q++;
        if(arr[q]-arr[p]==K) puts("YES");
        else puts("NO");
    }
    return 0;
}
