#include <cstdio>

using namespace std;

char s[10000];
int n, a, b, i;
char ch;
int main()
{
    scanf("%d", &n); getchar();
    while(n-- && scanf("%[^\n]s", s) && getchar())
    {
        a = b = i = 0;

        while(s[i] < '0' || s[i] > '9') ++i;
        while(s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' && s[i] != '%')
        {
            if(s[i] > '9' || s[i] < '0') {++i; continue;}
            a = (a << 1) + (a << 3) + s[i] - '0', ++i;
        }

        ch = s[i];

        while(s[i] < '0' || s[i] > '9') ++i;
        while(s[i])
        {
            if(s[i] > '9' || s[i] < '0') {++i; continue;}
            b = (b << 1) + (b << 3) + s[i] - '0', ++i;
        }

        switch(ch)
        {
            case '+':
                printf("%d", a + b);
                break;
            case '-':
                printf("%d", a - b);
                break;
            case '*':
                printf("%d", a * b);
                break;
            case '/':
                printf("%d", a / b);
                break;
            case '%':
                printf("%d", a % b);
        }
        putchar('\n');
    }

    return 0;
}
