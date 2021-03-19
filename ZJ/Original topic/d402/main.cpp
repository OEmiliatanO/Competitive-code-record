#include <cstdio>
#include <cstring>
using namespace std;
char s[1000];
int a,b,i;
int toInt32(int &i)
{
    int len=strlen(s);
    int r=0;
    while(i<len&&(s[i]<'0'||s[i]>'9')) i++;
    while(i<len&&(s[i]>='0'&&s[i]<='9')) r=r*10+s[i++]-'0';
    return r;
}
int main()
{
    while(~scanf("%[^\n]s",s)&&getchar())
    {
        i=0;
        if(a==0) a=toInt32(i);
        if(b==0) b=toInt32(i);
        if(a!=0&&b!=0) {printf("%d %d %lld\n",a,b,(long long)a+b); a=b=0;}
    }
    return 0;
}
