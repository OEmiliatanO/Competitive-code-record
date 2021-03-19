#include <cstdio>
#include <cctype>

using namespace std;

char s[1000];

int main()
{
    while(~scanf("%[^\n]s", s) && getchar())
        for(int i = 0; s[i]; putchar('\n'), i++)
        {
            while(s[i] == ' ') i++;
            for(int j = 0; j < i; j++)
                putchar(tolower(s[j]));
            putchar(toupper(s[i]));
            for(int j = i + 1; s[j]; j++)
                putchar(tolower(s[j]));
        }
    return 0;
}
