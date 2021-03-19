#include <cstdio>
using namespace std;
int ans[1001];
int main()
{
    int T,N,ans_size,i;scanf("%d",&T);
    while(T--&&scanf("%d",&N))
    {
        ans_size=0;
        for(i=2;(((2+i)*(i-1))>>1)<=N;ans_size++,i++)
            ans[i-2]=i;
        i--;
        N-=((2+i)*(i-1))>>1;
        for(i=ans_size-1;i>=0&&N>0;N--,i--)
        {
            ans[i]++;
            if(i==0) i=ans_size;
        }
        for(i=0;i<ans_size;i++) printf("%d ",ans[i]);
        puts("\n");
    }
    return 0;
}
