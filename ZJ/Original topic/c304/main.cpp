#include <cstdio>

using namespace std;

const int MAXN = 2000000000;
char ch;
long long ten, a, b;

int main()
{
    while(~(ch = getchar()))
    {
        ten = 10;
        b = a = ch - '0';
        while((ch = getchar()) != '\n')
        {
            ch -= '0';
            a = (a << 1) + (a << 3) + ch;
            b += ch * ten;
            ten = (ten << 1) + (ten << 3);
        }
        printf("%lld\n", a + b);
    }
    return 0;
}
