#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int N,cnt,tot,arr[51];
double pi;
int main()
{
    while(~scanf("%d",&N)&&N)
    {
        cnt=0,tot=N*(N-1)/2;
        for(int i=0;i<N&&scanf("%d",&arr[i]);i++);
        for(int i=0;i<N;i++)
            for(int j=i+1;j<N;j++)
                if(__gcd(arr[i],arr[j])==1)
                    cnt++;
        if(cnt==0)
            puts("No estimate for this data set.");
        else
        {
            pi=sqrt((double)6*tot/cnt);
            printf("%.6f\n",pi);
        }
    }
    return 0;
}
