#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,ans[501][3]={},ok[501]={};
    for(int a=0;a<16;a++)
        for(int b=0;b<a;b++)
            for(int c=0;c<b;c++)
            {
                int N=0;
                if(a>=3) N+=a*(a-1)*(a-2)/6;
                if(b>=2) N+=b*(b-1)/2;
                if(c>=1) N+=c;
                if(N>500) break;
                if(ok[N]==0)
                    ok[N]=1,ans[N][0]=a,ans[N][1]=b,ans[N][2]=c;
            }
    scanf("%d",&t);
    for(int in;t&&scanf("%d",&in)!=EOF;t--)
        printf("%d%d%d\n",ans[in][0],ans[in][1],ans[in][2]);
    return 0;
}
