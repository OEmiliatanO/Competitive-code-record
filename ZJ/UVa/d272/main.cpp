#include <cstdio>
#include <bitset>
using namespace std;
int t,N,ans;
bitset<26> record,tmp,K;
char s[27];
int main()
{
    scanf("%d",&t);
    while(~scanf("%d",&N))
    {
        ans=0;
        record.set();
        tmp.reset();
        for(int i=0;i<N&&scanf("%s",s);tmp.reset(),i++)
        {
            for(auto j:s)
            {
                if(!j) break;
                tmp[(j-'a')]=true;
            }
            K.set();
            K&=record;
            K&=tmp;
            if(K.any())
                record&=tmp;
            else ans++,record=tmp;
        }
        printf("%d\n",ans);
    }
    return 0;
}
