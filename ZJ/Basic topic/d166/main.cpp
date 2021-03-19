#include <cstdio>
#include <cstring>
#include <list>
using namespace std;
list<int> lis;
int len,arr[51],p;
char s[170];
int scan(int &i)
{
    int x=0;
    while(i<len&&(s[i]<'0'||s[i]>'9')) i++;
    while(i<len&&(s[i]>='0'&&s[i]<='9')) x=x*10+s[i++]-'0';
    return x;
}
int main()
{
    while(~scanf("%[^\n],",s)&&getchar()&&s[0]!='-')
    {
        lis.clear();
        p=0;
        len=strlen(s);
        for(int i=0;i<len;)
            arr[p++]=scan(i);
        for(p--;p>=0;p--)
        {
            int cnt=0;
            auto it=lis.begin();
            for(;it!=lis.end();it++)
                if(cnt==arr[p]) break;
                else if(*it>p+1) cnt++;
            lis.insert(it,p+1);
        }
        for(auto x:lis) printf("%d ",x);
        puts("");
    }
    return 0;
}
