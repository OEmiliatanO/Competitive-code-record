#include <cstdio>
#include <cmath>

using namespace std;

int i, l, n, sqr;
bool flag;

int main()
{
    while(~scanf("%d", &n) && getchar())
    {
        if(n == 1) {puts("1"); continue;}
        else if(n == -1) {puts("i"); continue;}
        else if(n == 0) {puts("0"); continue;}
        flag = (n < 0);
        n = abs(n);
        l = 1, sqr = sqrt(n);
        for(int x = 2; x <= sqr; x++)
        {
            while((n % (x * x)) == 0)
                l *= x, n /= x * x;
        }
        if(l != 1) printf("%d", l);
        if(n != 1) {putchar('_'); putchar('/'); printf("%d", n);}
        if(flag) putchar('i');
        putchar('\n');
    }
    return 0;
}
