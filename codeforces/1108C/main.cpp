#include <cstdio>
#include <cassert>
using namespace std;
char s[200001];
char Plan[6][4]={"RGB","GBR","BRG","GRB","RBG","BGR"};
int changeCnt[6]{};
int n,select;
int main()
{
    scanf("%d",&n);getchar();
    scanf("%[^\n]s",s);
    int p=0;
    for(auto ch:s)
    {
        if(!ch) break;
        for(int i=0;i<6;i++)
        {
            if(Plan[i][p]!=ch)
                changeCnt[i]++;
        }
        p++;
        p%=3;
    }
    for(int i=0,mini=1e9;i<6;i++)
        if(mini>changeCnt[i])
        {
            mini=changeCnt[i];
            select=i;
        }
    printf("%d\n",changeCnt[select]);
    for(int i=0,p=0;i<n;p%=3,i++)
        putchar(Plan[select][p++]);
    return 0;
}
