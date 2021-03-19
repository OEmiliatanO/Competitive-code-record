#include <cstdio>

using namespace std;

char ch;
bool flag = true;

int main()
{
    while((ch = getchar()) && ch == '-') flag = !flag;
    if(!flag && ch != '0') putchar('-');
    putchar(ch);
    while((ch = getchar()) && ch >= '0' && ch <= '9') putchar(ch);
    return 0;
}
