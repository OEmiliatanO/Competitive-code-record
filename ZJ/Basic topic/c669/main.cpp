#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
int T,si,len,d,used,sum;
set<int> st;
char s[10001];
int stringToint32(int &i)
{
    int res=0;
    while(i<len&&(s[i]>'9'||s[i]<'0')) i++;
    while(i<len&&(s[i]<='9'&&s[i]>='0')) res=(res<<3)+(res<<1)+s[i++]-'0';
    return res;
}
int main()
{
    scanf("%d",&T);getchar();
    while(T--&&scanf("%[^\n]s",s)&&getchar())
    {
        st.clear();
        si=used=0;
        len=strlen(s);
        while(si<len)
        {
            int x=stringToint32(si);
            if(st.find(x)!=st.end()) used=x;
            st.emplace(x);
        }
        sum=(*st.begin()+*next(st.end(),-1))*(st.size()+1);
        sum>>=1;
        for(int i:st) sum-=i;
        printf("%d %d\n",sum,used);
    }
    return 0;
}
