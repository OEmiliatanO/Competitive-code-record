#include <cstdio>
typedef unsigned long long uint64;
uint64 ans[101][101]{};
int N,M;
int main()
{
    ans[1][0]=ans[1][1]=1;
	for(int i=2;i<101;i++)
    {
        ans[i][0]=1;
        for(int j=1;j<i;j++)
            ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
        ans[i][i]=1;
    }
    while(~scanf("%d %d",&N,&M)&&(N|M)) printf("%d things taken %d at a time is %llu exactly.\n",N,M,ans[N][M]);
    return 0;
}
