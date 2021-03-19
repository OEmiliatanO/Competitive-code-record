#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;
typedef long long int64;
int cent[10]={1,5,10,20,50,100,200,500,1000,2000};
int64 ans[50010];
char s[1000];
int len,p,taget;
int stringToint(int &i)
{
    int res=0;
    while(i<len&&(s[i]<'0'||s[i]>'9')) i++;
    while(i<len&&s[i]>='0'&&s[i]<='9') res=res*10+s[i]-'0',i++;
    return res;
}
void DP()
{
    ans[0]=1;
    for(int i=0;i<10;i++)
        for(int j=cent[i];j<50001;j++)
            ans[j]+=ans[j-cent[i]];
}
int main()
{
    DP();
    while(~scanf("%[^\n]s",s)&&getchar())
    {
        p=taget=0;
        len=strlen(s);
        while(p<len) taget+=stringToint(p);
        if(taget==0) return 0;
        printf("%lld\n",ans[taget]-1);
    }
    return 0;
}
