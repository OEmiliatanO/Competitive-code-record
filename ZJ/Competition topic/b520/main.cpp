#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
char answer[20],guess[20];
int n,ai,gi,al,gl,right;
set<int> ans;
int scan(char s[],int &p,int len)
{
    int r=0;
    while(p<len&&(s[p]<'0'||s[p]>'9')) p++;
    while(p<len&&(s[p]>='0'&&s[p]<='9')) r=r*10+s[p++]-'0';
    return r;
}
int main()
{
    scanf("%d",&n);getchar();
    while(n--)
    {
        ans.clear();
        ai=gi=right=0;
        scanf("%[^\n]s",answer);getchar();
        scanf("%[^\n]s",guess);getchar();
        al=strlen(answer);
        gl=strlen(guess);
        while(ai<al)
            ans.emplace(scan(answer,ai,al));
        while(gi<gl)
            if(ans.count(scan(guess,gi,gl))) right++;
        printf("%d\n",right);
    }
    return 0;
}
