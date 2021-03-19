#include <cstdio>
using namespace std;
int _hash(char ch)
{
    if(ch==' ')
        return 26;
    return ch-'a';
}
int cnt[27]{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,3,4,1,2,3,1,2,3,4,1};
int t,sum,kase=1;
char s[101];
int main()
{
    for(int i=0,c=1;i<15;c=(c==4?1:c),i++)
        cnt[i]=c++;
    scanf("%d",&t);getchar();
    while(t--&&scanf("%[^\n]s",s)&&getchar())
    {
        sum=0;
        for(auto ch:s)
        {
            if(!ch) break;
            sum+=cnt[_hash(ch)];
        }
        printf("Case #%d: %d\n",kase++,sum);
    }
    return 0;
}
