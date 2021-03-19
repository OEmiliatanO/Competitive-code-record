#include <cstdio>
using namespace std;
char ch;
bool left_flag=true;
int main()
{
    while(~(ch=getchar()))
    {
        if(ch=='"')
            if(left_flag) printf("``"),left_flag=!left_flag;
            else printf("''"),left_flag=!left_flag;
        else putchar(ch);
    }
    return 0;
}
