#include <cstdio>
using namespace std;
int main()
{
    int T,n,ans=0;scanf("%d",&T);
    char farm[100];
    for(int t=1;t<=T&&scanf("%d",&n);t++,ans=0)
    {
        getchar();
        for(int i=0;i<n&&scanf("%c",&farm[i]);i++);
        for(int i=0;i<n;i++)
            if(farm[i]=='.')
            {
                ans++;
                farm[i]='#';
                if(i+1<n) farm[i+1]='#';
                if(i+2<n) farm[i+2]='#';
            }
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
