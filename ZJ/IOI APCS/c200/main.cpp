#include <cstdio>
#include <cstring>
using namespace std;
const int mod=1688;
int T,len,ans,lim;
char s[101];
inline int hash_(char ch)
{
    if(ch>='0'&&ch<='9')
        return ch-'0';
    else if(ch>='A'&&ch<='Z')
        return ch-'A'+10;
    return 0;
}
int main()
{
    scanf("%d",&T);getchar();
    while(T--&&scanf("%[^\n]s",s)&&getchar())
    {
        ans=0;
        len=strlen(s);
        for(int i=0;i<len;i++) if(s[i]==0) lim=i;
        for(int i=lim;i<len;i++)
            ans=(ans*36+hash_(s[i]))%mod;
        ans%=mod;
        printf("%d\n",ans+1);
    }
    return 0;
}
