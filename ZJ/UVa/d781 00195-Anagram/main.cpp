#include <cstdio>
#include <cstring>
#include <algorithm>
#define IsBig(x) ((x)>='A'&&(x)<='Z'?true:false)
using namespace std;
int n,len;
char s[100];
bool cmp(const char &a,const char &b)
{
    int a_copy,b_copy;
    if(IsBig(a)) a_copy=(a-'A')*2;
    else a_copy=(a-'a')*2+1;
    if(IsBig(b)) b_copy=(b-'A')*2;
    else b_copy=(b-'a')*2+1;
    return a_copy<b_copy;
}
int main()
{
    scanf("%d",&n);getchar();
    while(n--&&scanf("%[^\n]s",s)&&getchar())
    {
        len=strlen(s);
        sort(s,s+len,cmp);
        do
        {
            printf("%s\n",s);
        }while(next_permutation(s,s+len,cmp));
    }
    return 0;
}
