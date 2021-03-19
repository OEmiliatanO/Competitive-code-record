#include <cstdio>
#include <cmath>

using namespace std;

int a, b, n;

int main()
{
    while(~scanf("%d", &n) && n)
    {
        a = ceil((double)sqrt(n));
        b = (a - 1) * (a - 1) + a;
        if(a & 1)
        {
            if(n >= b)
                printf("%d %d\n", a - (n - b), a);
            else
                printf("%d %d\n", a, a - (b - n));
        }
        else
        {
            if(n >= b)
                printf("%d %d\n", a, a - (n - b));
            else
                printf("%d %d\n", a - (b - n), a);
        }
    }
    return 0;
}
