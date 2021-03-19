#include <cstdio>
using namespace std;
const int MAXN=100001;
char s[MAXN];
int Q=0,nowQ=0;
long long ans=0;
int main()
{
    scanf("%[^\n]s",s);
    for(auto ch:s)
        if(ch=='Q') Q++;
        else if(!ch) break;
    for(auto ch:s)
        if(!ch) break;
        else if(ch=='A') ans+=nowQ*(Q-nowQ);
        else if(ch=='Q') nowQ++;
    printf("%lld",ans);
    return 0;
}
