#include <cstdio>
using namespace std;
char ch;
int cnt;
int main()
{
    cnt=0;
    while((ch=getchar())&&ch!=EOF)
    {
        if(ch=='\n') {putchar('\n'); cnt=0;}
        else if(ch=='!') putchar('\n');
        else if(ch>='0'&&ch<='9') cnt+=ch-'0';
        else if(ch>='A'&&ch<='Z'||ch=='*')
        {
            for(int i=0;i<cnt;i++)
                putchar(ch);
            cnt=0;
        }
        else if(ch=='b')
        {
            for(int i=0;i<cnt;i++)
                putchar(' ');
            cnt=0;
        }
    }
    return 0;
}
