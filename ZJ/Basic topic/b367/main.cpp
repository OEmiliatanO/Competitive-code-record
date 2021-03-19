#include <cstdio>
using namespace std;
int T,N,M,arr[11][11];
bool ans=true;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        ans=true;
        scanf("%d %d",&N,&M);
        for(int i=0;i<N;i++)
            for(int j=0;j<M&&scanf("%d",&arr[i][j]);j++);
        for(int top=0,bottom=N-1;ans&&top<=bottom;top++,bottom--)
            for(int xt=0,xb=M-1;ans&&xt<M&&xb>=0;xt++,xb--)
                if(arr[top][xt]!=arr[bottom][xb]) ans=false;
        printf((ans?"go forward\n":"keep defending\n"));
    }
    return 0;
}
