#include <cstdio>

using namespace std;

int sum;
char ch;

int main()
{
    for(int i = 0; i < 9; putchar('\n'), sum = 0, i++)
    {
        while((ch=getchar()) && ch != '\n')
            sum += ch - '0';
        putchar(45 - sum + '0');
    }
    return 0;
}
