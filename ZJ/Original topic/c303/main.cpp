#include <cstdio>
#include <cctype>

using namespace std;

const int MAXN = 100000;
int n;
char s[MAXN];

int main()
{
    while(~scanf("%d", &n) && getchar())
    {
        scanf("%[^\n]s", s); getchar();
        for(auto ch : s)
        {
            if(!ch) break;
            if(ch >= 'A' && ch <= 'Z') putchar(tolower(ch));
            else putchar(toupper(ch));
        }
        putchar('\n');
    }
    return 0;
}
