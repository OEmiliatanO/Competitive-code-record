#include <cstdio>
using namespace std;
int ans=0;
int AddAll(int N)
{
    for(int i=1;i<N;i++)
        if(N%i==0)
            ans+=i;
    return ans;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int N,S;n--&&scanf("%d",&N);ans=0)
    {
        S=AddAll(N);
        if(S>N)
            printf("abundant\n");
        else if(N>S)
            printf("deficient\n");
        else if(N==S)
            printf("perfect\n");
    }
    return 0;
}
