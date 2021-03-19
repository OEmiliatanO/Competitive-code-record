#include <cstdio>
#include <string.h>
#include <string>
using namespace std;
int num[25];
int main()
{
    for(int N,M;scanf("%d %d",&N,&M)!=EOF&&N&&M;)
    {
        int sum=0,ans[25],p=0;
        bool have_ans=false;
        string result="";
        memset(num,0,sizeof(num));
        for(int i=0;i<N;i++)
        {
            for(int j=0,in;j<M&&scanf("%d",&in);j++)
                num[i]=(num[i]<in?in:num[i]);
            sum+=num[i];
        }
        printf("%d\n",sum);
        for(int i=0;i<N;i++)
            if(!(sum%num[i])) {have_ans=true; ans[p++]=num[i];}
        if(have_ans)
            for(int i=0;i<p;i++)
            {
                printf("%d",ans[i]);
                if(i!=p-1)
                    printf(" ");
            }
        else
            printf("-1");
        printf("\n");
    }
    return 0;
}
